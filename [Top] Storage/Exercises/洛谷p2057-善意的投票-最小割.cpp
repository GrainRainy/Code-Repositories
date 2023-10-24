#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 10;
int n, m, s, t, head[N], now[N], etp = 1, ans;
struct Node { int nxt, to, f; }edge[N * N + N + N];
int dis[N];

inline void add(int a, int b, int f) {
	edge[++ etp] = {head[a], b, f};
	head[a] = etp;
}

bool bfs() {
	queue<int> q;
	memset(dis, 0x3f, sizeof dis);
	q.push(s), dis[s] = 0, now[s] = head[s];
	while(q.size()) {
		int u = q.front(); q.pop();
		for (int i = head[u], v; ~i; i = edge[i].nxt) 
			if (edge[i].f and dis[v = edge[i].to] == 0x3f3f3f3f) {
				dis[v] = dis[u] + 1, now[v] = head[v], q.push(v);
				if (v == t) return true;
			}
	}
	return false;
}

int dfs(int u, int lim) {
	if (u == t) return lim;
	int res = lim, tmp;
	for (int i = now[u], v; ~i and res; i = edge[i].nxt) {
		now[u] = i, v = edge[i].to;
		if (dis[v] == dis[u] + 1 and edge[i].f) {
			tmp = dfs(v, min(edge[i].f, res));
			if (!tmp) dis[v] = 0x3f3f3f3f;
			edge[i].f -= tmp, edge[i ^ 1].f += tmp, res -= tmp;
		}
	}
	return lim - res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m, s = n + 1, t = n + 2;
	memset(head, -1, sizeof head);
	for (int i = 1, x; i <= n; ++ i) {
		cin >> x;
		if (x) add(s, i, 1), add(i, s, 0);
		else add(i, t, 1), add(t, i, 0);
	}
	for (int i = 1, a, b; i <= m; ++ i) {
		cin >> a >> b;
		add(a, b, 1), add(b, a, 0), add(b, a, 1), add(a, b, 0);
	}
	while (bfs()) ans += dfs(s, 0x3f3f3f3f);
	return cout << ans << '\n', 0;
}
