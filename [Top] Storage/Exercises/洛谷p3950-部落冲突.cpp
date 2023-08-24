#include <iostream>
#include <cstring>
#include <algorithm>

#define lowbit(x) ((x) & -(x))

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

const int N = 3e5 + 10;
int n, m, u, v, WarTop;
char op[3];
struct War{
    int u, v;
}war[N];
// basis 
int head[N], idx;
struct Node {
    int nxt, to;
}edge[N << 1];
// graph 
int tree[N];
// Binary Indexed Tree 
int siz[N], fa[N], dep[N], hs[N];
int stamp, dfn[N], top[N];
// cuttings 

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

void modify(int u, int k) {
    for (; u <= n; u += lowbit(u)) 
        tree[u] += k;
}

int query(int r) {
    int res = 0;
    for (; r > 0; r -= lowbit(r)) 
        res += tree[r];
    return res;
}

void ModifyVertex(int u, int v, int k) {
    if (dep[u] < dep[v]) swap(u, v);
    return modify(dfn[u], k);
}

int QueryPath(int u, int v) {
    int res = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        res += query(dfn[u]) - query(dfn[top[u]] - 1);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    res += query(dfn[u]) - query(dfn[v]);
    return res;
}

int main() {
    memset(head, -1, sizeof head);
    input(n), input(m);
    for (int i = 1; i < n; i ++) {
        input(u), input(v);
        add(u, v), add(v, u);
    }
    
    dfs1(1, 1, 1);
    dfs2(1, 1);

    while (m --) {
        cin >> op; 
        if (op[0] == 'Q') {
            input(u), input(v);
            (!QueryPath(u, v)) ? puts("Yes") : puts("No");
        }
        if (op[0] == 'C') {
            input(u), input(v);
            war[ ++ WarTop] = {u, v};
            ModifyVertex(u, v, 1);
        }
        if (op[0] == 'U') {
            input(u);
            ModifyVertex(war[u].u, war[u].v, -1);
        }
    }
    return 0;
}
