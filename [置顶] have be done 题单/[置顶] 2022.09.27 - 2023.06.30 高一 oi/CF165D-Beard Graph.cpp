#include <iostream>
#include <cstring>
#include <algorithm>

#define __DEBUG__ puts("YES");

#define lson (u << 1)
#define rson (u << 1 | 1)

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
    x = 0; char c = getchar();
    bool f = false;
    for (; !isdigit(c); c = getchar())
        f |= (c == '-');
    for (; isdigit(c); c = getchar())
        x = x * 10 + ( c ^ '0');
    if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n') {
    if (x < 0) return puts("-1"), void();
    static short st[20], top;
    do st[++ top] = x % 10, x /= 10; while (x);
    while (top) putchar(st[top --] | '0');
    putchar(ed);
}

const int N = 1e5 + 10;
const int M = 3e5 + 10;
const int INF = 0x3f3f3f3f;

int n, m, u, v, op;
struct Save {
    int a, b;
}save[N];

int head[N], idx;
struct Node {
    int nxt, to;
}edge[N << 1];
// graph 
struct SegmentTree {
    int l, r;
    LL sum, tag;

    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define tag(x) tree[x].tag
}tree[N << 2];
// SegmentTree
int siz[N], fa[N], dep[N], hs[N];
int stamp, dfn[N], top[N];

inline void add(int a, int b) {
    edge[++ idx].nxt = head[a];
    edge[head[a] = idx].to = b;
}

void dfs1(int u, int father, int depth) {
    dep[u] = depth, fa[u] = father, siz[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int j = edge[i].to;
        if (j == father) continue;
        dfs1(j, u, depth + 1);
        siz[u] += siz[j];
        if (siz[j] > siz[hs[u]]) hs[u] = j;
    }
}

void dfs2(int u, int Top) {
    dfn[u] = ++ stamp, top[u] = Top;
    if (!hs[u]) return;
    dfs2(hs[u], Top);
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int j = edge[i].to;
        if (j == fa[u] or j == hs[u]) continue;
        dfs2(j, j);
    }
}

void PushUp(int u) {
    sum(u) = sum(lson) + sum(rson);
}

void PushDown(int u) {
    if (!tag(u)) return;
    sum(lson) = (r(lson) - l(lson) + 1) * tag(u);
    sum(rson) = (r(rson) - l(rson) + 1) * tag(u);
    tag(lson) = tag(u), tag(rson) = tag(rson);
    tag(u) = 0;
}

void build(int u, int l, int r) {
    tree[u] = {l, r, r - l + 1, 0};
    if (l == r) return;
    int mid = l + r >> 1;
    build(lson, l, mid), build(rson, mid + 1, r);
    PushUp(u);
}

void change(int u, int l, int r, int k) {
    if (l > r(u) or r < l(u)) return;
    if (l(u) >= l and r(u) <= r) {
        sum(u) = (r(u) - l(u) + 1) * k;
        tag(u) = k;
        return;
    }
    PushDown(u);
    change(lson, l, r, k), change(rson, l, r, k);
    PushUp(u);
}

LL query(int u, int l, int r) {
    if (l > r(u) or r < l(u)) return 0;
    if (l(u) >= l and r(u) <= r) return sum(u);
    PushDown(u);
    return query(lson, l, r) + query(rson, l, r);
}

void ChangeEdge(int u, int v, int k) {
    if (dep[u] < dep[v]) swap(u, v);
    change(1, dfn[u], dfn[u], k);
}

LL QueryPath(int u, int v) {
    LL res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        res += query(1, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    res += query(1, dfn[v] + 1, dfn[u]);
    return res;
}

int main() {
	memset(head, -1, sizeof head);
    input(n);
    for (int i = 1; i < n; ++ i) {
        input(u), input(v);
        save[i] = {u, v};
        add(u, v), add(v, u);
    }

    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);

	input(m);
    while (m --) {
        input(op);
        if (op == 1) {
            input(u);
            ChangeEdge(save[u].a, save[u].b, 1);
        }
        if (op == 2) {
            input(u);
            ChangeEdge(save[u].a, save[u].b, -INF);
        }
        if (op == 3) {
            input(u), input(v);
            output(QueryPath(u, v));
        }
    }
    return 0;
}
