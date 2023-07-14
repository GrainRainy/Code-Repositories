#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace IO;
using namespace std;
using LL = long long;

const int INF = 1e9;
const int N = 200 + 10;
const int M = 5e3 + 10;

int n, m, s, t, u, v; LL w, maxFlow;
int head[N], now[N], idx = 1;
struct Node { int nxt, to; LL w; } edge[M << 1];
// graph 
int dis[N], pos[N][N];

inline void add(int a, int b, LL w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

bool bfs() {
	for (int i = 1; i <= n; ++ i) dis[i] = 0;
	queue<int> q;
	q.push(s), dis[s] = 1, now[s] = head[s];
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (edge[i].w and !dis[j]) {
				q.push(j), dis[j] = dis[u] + 1, now[j] = head[j];
				if (j == t) return true;
			}
		}
	}
	return false;
}

int dfs(int u, LL flow) {
	if (u == t) return flow;
	LL k, res = flow;
	for (int i = now[u], j; ~i and res; i = edge[i].nxt) {
		now[u] = i;
		j = edge[i].to;
		if (edge[i].w and (dis[j] == dis[u] + 1)) {
			k = dfs(j, min(res, edge[i].w));
			if (!k) dis[j] = 0;
			edge[i].w -= k;
			edge[i ^ 1].w += k;
			res -= k;
		}
	}
	return flow - res;
}

int main() {
	input(n), input(m), input(s), input(t);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= m; ++ i) {
		input(u), input(v), input(w);
		if (pos[u][v]) edge[pos[u][v]].w += w;
		else add(u, v, w), pos[u][v] = idx, add(v, u, 0);
	}
	while (bfs()) maxFlow += dfs(s, INF);
	cout << maxFlow << endl;
	return 0;
}
