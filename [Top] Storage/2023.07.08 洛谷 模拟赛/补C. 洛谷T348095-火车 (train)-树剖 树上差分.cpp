#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
} 

using IO::input;
using namespace std;
using LL = long long;
const int N = 5e5 + 10;
int n, m, p[N];
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int fa[N], dep[N], siz[N], dfn[N], stamp, hs[N], top[N];
LL tree[N], res;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int depth, int father) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs1(j, depth + 1, u);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	top[u] = Top, dfn[u] = ++ stamp;
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

void modify(int pos, int val) {
	for (; pos <= n; pos += lowbit(pos))
		tree[pos] += val;
}

int query(int pos) {
	int res = 0;
	for (; pos; pos -= lowbit(pos)) res += tree[pos];
	return res;
}

void modifyChain(int u, int v) {
	int tmpu = u, tmpv = v;
	modify(dfn[u], 1), modify(dfn[v], 1);
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	int lca = dep[u] < dep[v] ? u : v;
	modify(dfn[lca], -1);
	if (fa[lca]) modify(dfn[fa[lca]], -1);
	res += dep[tmpu] + dep[tmpv] - (dep[lca] << 1);
}

int main() {
	input(n), input(m), input(p[0]);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, x, y; i < n; ++ i) {
		input(x), input(y);
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= m; ++ i) input(p[i]);
	dfs1(p[0], 1, 0), dfs2(p[0], p[0]);
	
	int pre = p[0];
	for (int i = 1; i <= m; ++ i) {
		if (query(dfn[p[i]] + siz[p[i]] - 1) - query(dfn[p[i]] - 1)) continue;
		modifyChain(pre, p[i]); 
		pre = p[i];
	}
	return printf("%ld\n", res), 0;
}
