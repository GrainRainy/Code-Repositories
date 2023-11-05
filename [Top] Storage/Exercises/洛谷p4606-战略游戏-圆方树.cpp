#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e5 + 10;
int n, m, q, head[N], etp;
struct Node { int nxt, to; }edge[N << 2];
int dfn[N], low[N], stk[N], tp, stp, dct;
vector<int> g[N << 1];
int siz[N << 1], fa[N << 1], hs[N << 1], dep[N << 1], dis[N << 1];
int ndfn[N << 1], top[N << 1], nstp;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++ stp, stk[++ tp] = u;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if (!dfn[v = edge[i].to]) {
			tarjan(v), low[u] = min(low[u], low[v]);
			if (low[v] == dfn[u]) {
				dct ++; int tmp;
				g[u].emplace_back(dct);
				g[dct].emplace_back(u);
				do {
					tmp = stk[tp --];
					g[dct].emplace_back(tmp);
					g[tmp].emplace_back(dct);
				} while (tmp != v);
			}
		} else low[u] = min(low[u], dfn[v]);
	}
}

void dfs1(int u, int father, int depth) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	dis[u] = dis[father] + (u <= n), top[u] = 0;
	for (auto v : g[u])	if (v != father) {
		dfs1(v, u, depth + 1), siz[u] += siz[v];
		if (siz[v] > siz[hs[u]]) hs[u] = v;
	}
}

void dfs2(int u, int t) {
	top[u] = t, ndfn[u] = ++ nstp;
	if (hs[u]) dfs2(hs[u], t);
	for (auto v : g[u]) if (!top[v]) dfs2(v, v);
}

int lca(int a, int b) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

void solve() {
	rd(n), rd(m), dct = n, tp = etp = stp = nstp = 0;
	memset(dfn, 0, sizeof(int) * (n + 10));
	memset(low, 0, sizeof(int) * (n + 10));
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i <= m; ++ i) 
		rd(a), rd(b), add(a, b), add(b, a);
	tarjan(1), dfs1(1, 0, 1), dfs2(1, 1), rd(q), tp = 0;
	for (int i = 1, cc, x, ans; i <= q; ++ i) {
		rd(cc), tp = ans = 0;
		for (int j = 1; j <= cc; ++ j) rd(x), stk[++ tp] = x;
		sort(stk + 1, stk + tp + 1, [](int a, int b) { return ndfn[a] < ndfn[b]; });
		for (int j = 1; j <= cc; ++ j) 
			ans += dis[stk[j]] + dis[stk[j % cc + 1]] - (dis[lca(stk[j], stk[j % cc + 1])] << 1);
		ot((ans >> 1) - cc + (lca(stk[1], stk[cc]) <= n));
	}
	for (int i = 1; i <= dct; ++ i) g[i].clear();
	memset(hs, 0, sizeof(int) * (dct + 10));
}

int main() {
//	freopen("game.in", "r", stdin);
	int t; rd(t);
	while (t --) solve();
	return 0;
}
