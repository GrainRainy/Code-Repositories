#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m, s[N], t[N], sm[N], head[N], idx;
struct Node { int nxt, to, w; }edge[N << 1];
int dep[N], dis[N], siz[N], fa[N], hs[N], dfn[N], node[N], top[N], stamp;
int l, r, mid, ps[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
	edge[idx].w = c;
}

void dfs1(int u, int father, int depth, int dist) {
	fa[u] = father, dis[u] = dist, dep[u] = depth, siz[u] = 1;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		v = edge[i].to;
		if (v == father) continue;
		dfs1(v, u, depth + 1, dist + edge[i].w);
		siz[u] += siz[v];
		if (siz[v] > siz[hs[u]]) hs[u] = v;
	}
}

void dfs2(int u, int t) {
	dfn[u] = ++ stamp, node[stamp] = u, top[u] = t;
	if (!hs[u]) return;
	dfs2(hs[u], t);
	for (int i = head[u], v; ~i; i = edge[i].nxt) 
		if (!top[v = edge[i].to]) dfs2(v, v);
}

int lca(int a, int b) {
	while (top[a] ^ top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

bool check(int mid) {
	int c = 0, mx = 0;
	memset(ps, 0, sizeof(int) * (n + 10));
	for (int i = 1; i <= m; ++ i) 
		if (sm[i] > mid) {
			c ++, ps[s[i]] ++, ps[t[i]] ++, ps[lca(s[i], t[i])] -= 2;
			mx = max(mx, sm[i] - mid);
		}
	if (!c) return true;
	for (int i = n; i; -- i) ps[fa[node[i]]] += ps[node[i]];
	for (int i = 2; i <= n; ++ i) 
		if (ps[i] == c and dis[i] - dis[fa[i]] >= mx) return true;
	return false;
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b, c; i < n; ++ i)
		rd(a), rd(b), rd(c), add(a, b, c), add(b, a, c);
	dfs1(1, 0, 1, 0), dfs2(1, 1);
	for (int i = 1; i <= m; ++ i) {
		rd(s[i]), rd(t[i]), sm[i] = dis[s[i]] + dis[t[i]] - dis[lca(s[i], t[i])] * 2;
		r = max(sm[i], r);
	}
	while (l < r) check(mid = l + r >> 1) ? r = mid : l = mid + 1;
	return cout << l << '\n', 0;
}
