#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
int n, m, p[N], head[N], etp;
struct Save { int a, b; LL w; }sv[N];
struct Node { int nxt, to; LL w; }edge[N << 1];
int fa[N], dep[N], siz[N], hs[N], top[N];
LL c, faw[N];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
inline void add(int a, int b, LL c) {
	edge[++ etp].nxt = head[a];
	edge[etp].w = c;
	edge[head[a] = etp].to = b;
}

void dfs1(int u, int father, int depth) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == father) continue;
		faw[v] = edge[i].w;
		p[v] = faw[v] == 1 ? find(u) : v;
		dfs1(v, u, depth + 1);
		siz[u] += siz[v];
		if (siz[v] > siz[hs[u]]) hs[u] = v;
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	if (!hs[u]) return;
	dfs2(hs[u], t);
	for (int i = head[u], v; ~i; i = edge[i].nxt) 
		if (!top[v = edge[i].to]) dfs2(v, v);
}

int lca(int a, int b) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) {
		p[i] = i;
		cin >> a >> b >> c;
		sv[i] = {a, b, c};
		add(a, b, c), add(b, a, c);
	}
	p[n] = n, dfs1(1, 0, 1), dfs2(1, 1);
	for (int i = 1, op, a, b, pos, l; i <= m; ++ i) {
		cin >> op;
		if (op == 1) {
			cin >> a >> b >> c;
			l = lca(a, b);
			while (dep[a] > dep[l] and c) c /= faw[a], a = find(fa[a]);
			while (dep[b] > dep[l] and c) c /= faw[b], b = find(fa[b]);
			cout << c << '\n';
		} else if (op == 2) {
			cin >> pos >> c;
			if (dep[sv[pos].a] < dep[sv[pos].b]) swap(sv[pos].a, sv[pos].b);
			faw[sv[pos].a] = sv[pos].w = c;
			if (c == 1) p[sv[pos].a] = find(sv[pos].b);
		}
	}
	return 0;
}
