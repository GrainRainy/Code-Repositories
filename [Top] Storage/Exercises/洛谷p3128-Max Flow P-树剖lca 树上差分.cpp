#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int n, k, head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int siz[N], dep[N], fa[N], sm[N], hs[N], top[N], ans;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int father, int depth) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == father) continue;
		dfs1(v, u, depth + 1);
		siz[u] += siz[v];
		if (siz[v] > siz[hs[u]]) hs[u] = v;
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	if (hs[u]) dfs2(hs[u], t);
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if (!top[v = edge[i].to]) dfs2(v, v);
}

void dfs3(int u) {
	for (int i = head[u], v; ~i; i = edge[i].nxt) 
		if ((v = edge[i].to) != fa[u]) dfs3(v), sm[u] += sm[v];
	ans = max(ans, sm[u]);
}

int lca(int a, int b) {
	while (top[a] ^ top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i)
		cin >> a >> b, add(a, b), add(b, a);
	dfs1(1, 1, 0), dfs2(1, 1);
	for (int i = 1, a, b, t; i <= k; ++ i) {
		cin >> a >> b, t = lca(a, b);
		sm[a] ++, sm[b] ++, sm[t] --, sm[fa[t]] --;
	}
	dfs3(1);
	return cout << ans << '\n', 0;
}
