#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int n, ace, xxk, head[N], idx;
struct Node { int nxt, to, w; }edge[N << 1];
int siz[N], dep[N], fa[N], hs[N], top[N], dis[2][N];
string col;

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int father, int depth) {
	siz[u] = 1, fa[u] = father, dep[u] = depth;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs1(j, u, depth + 1);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	if (!hs[u]) return;
	dfs2(hs[u], t);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

int lca(int a, int b) {
	while (top[a] ^ top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

void dfs(int u, int father, int type, bool judge = 0) {
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father or edge[i].w == !type) continue;
		dis[type][j] = dis[type][u] + 1;
		if (judge and INF == dis[!type][u] and INF == dis[!type][j])
			cout << "ji\n", exit(0);
		dfs(j, u, type, judge);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> ace >> xxk;
	memset(dis, 0x3f, sizeof dis);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) {
		cin >> a >> b >> col;
		add(a, b, col == "black" ? 2 : col == "blue" ? 0 : 1);
		add(b, a, col == "black" ? 2 : col == "blue" ? 0 : 1);
	}
	bool f1 = false, f2 = false;
	for (int i = head[ace]; ~i; i = edge[i].nxt)
		if (edge[i].w != 1 and edge[i].to != xxk) f1 = true;
	if (!f1) return cout << "xixike\n", 0;
	for (int i = head[xxk]; ~i; i = edge[i].nxt)
		if (edge[i].w != 0 and edge[i].to != ace) f2 = true;
	if (!f2) return cout << "Acestar\n", 0;
	dfs1(1, 1, 0), dfs2(1, 1);
	dis[0][ace] = dis[1][xxk] = 0;
	int dist = dep[ace] + dep[xxk] - (dep[lca(ace, xxk)] << 1);
	dist & 1 ? dfs(xxk, 0, 1) : dfs(ace, 0, 0);
	dist & 1 ? dfs(ace, 0, 0, 1) : dfs(xxk, 0, 1, 1);
	cout << (dist & 1 ? "xixike" : "Acestar") << '\n';
	return 0;
}
