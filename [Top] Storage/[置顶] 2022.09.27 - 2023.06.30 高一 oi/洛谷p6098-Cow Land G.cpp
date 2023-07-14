#include <iostream>
#include <cstring>
#include <algorithm>

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
        x = x * 10 + (c ^ '0');
    if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n') {
    if (x < 0) putchar('-'), x = -x;
    static short st[20], top;
    do st[ ++ top] = x % 10, x /= 10; while (x);
    while (top) putchar(st[top -- ] | '0');
    putchar(ed);
}

const int N = 1e5 + 10;
int n, q, u, v, op;
int w[N];
// basis 
int head[N], idx;
struct Node {
    int nxt, to;
}edge[N << 1];
// graph
struct SegmentTree {
    int l, r;
    int sum;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
}tree[N << 2];
// Segment Tree 
int dep[N], siz[N], fa[N], hs[N], mv[N];
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
    dfn[u] = ++ stamp, top[u] = Top, mv[dfn[u]] = w[u];
    if (!hs[u]) return;
    dfs2(hs[u], Top);
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int j = edge[i].to;
        if (j == fa[u] or j == hs[u]) continue;
        dfs2(j, j);
    }
}

inline void PushUp(int u) {
    sum(u) = sum(lson) ^ sum(rson);
}

void build(int u, int l, int r) {
	l(u) = l, r(u) = r;
    if (l == r) {
        sum(u) = mv[l];
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid), build(rson, mid + 1, r);
    PushUp(u);
}

void modify(int u, int l, int r, int k) {
    if (l > r(u) or r < l(u)) return;
    if (l <= l(u) and r >= r(u)) return sum(u) = k, void();
    modify(lson, l, r, k), modify(rson, l, r, k);
    PushUp(u);
}

int query(int u, int l, int r) {
    if (l > r(u) or r < l(u)) return 0;
    if (l <= l(u) and r >= r(u)) return sum(u);
    return query(lson, l, r) ^ query(rson, l, r);
}

int QueryPath(int u, int v) {
    int res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        res ^= query(1, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    res ^= query(1, dfn[v], dfn[u]);
    return res;
}

int main() {
    memset(head, -1, sizeof head);
    input(n), input(q);
    for (int i = 1; i <= n; i ++) input(w[i]);
    for (int i = 1; i < n; i ++) {
        input(u), input(v);
        add(u, v), add(v, u);
    }

    dfs1(1, 1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    
    while (q --) {
        input(op), input(u), input(v);
        if (op == 1) modify(1, dfn[u], dfn[u], v);
        if (op == 2) output(QueryPath(u, v));
    }
    
//    puts("__DEBUG__");
//    for (int i = 1; i <= 10; i ++) {
//    	cout << l(i) << " " << r(i) << " " << sum(i) << endl;
//	}
    return 0;
}
