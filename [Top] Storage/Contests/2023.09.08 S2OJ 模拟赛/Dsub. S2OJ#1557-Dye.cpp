#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, ace, xxk, head[N], idx;
string col;
struct Node { int nxt, to; }edge[N << 1];
int dep[N], siz[N], hs[N], fa[N], top[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int depth, int father) {
	siz[u] = 1, dep[u] = depth, fa[u] = father;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs1(j, depth + 1, u);
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
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> ace >> xxk;
	memset(head, -1, sizeof head);
	for (int i = 1, a, b; i < n; ++ i) {
		cin >> a >> b >> col;
		add(a, b), add(b, a);
		if (col != "black") return cout << "ji\n", 0;
	}
	dfs1(1, 1, 0), dfs2(1, 1);
	int dis = dep[ace] + dep[xxk] - (dep[lca(ace, xxk)] << 1);
	if (dis & 1) cout << "xixike\n";
	else cout << "Acestar\n";
	return 0;
}
