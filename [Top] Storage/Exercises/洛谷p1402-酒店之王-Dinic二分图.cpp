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

const int INF = 0x3f3f3f3f;
const int N = 4e2 + 10;
const int M = 2e4 + 10;
int n, p, q, tmp, s, t, maxFlow;
int head[N], now[N], idx = 1;
struct Node { int nxt, to, w; }edge[M << 1];
int dis[N];

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

bool bfs() {
	for (int i = 0; i <= n; ++ i) dis[i] = INF;
	queue<int> q;
	q.push(s), dis[s] = 0, now[s] = head[s];
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (edge[i].w and dis[j] == INF) {
				dis[j] = dis[u] + 1;
				q.push(j); now[j] = head[j];
				if (j == t) return true;
			}
		}
	}
	return false;
}

int dfs(int u, int limit) {
	if (u == t) return limit;
	int res = limit;
	for (int i = now[u], j; ~i and res; i = edge[i].nxt) {
		now[u] = i;
		j = edge[i].to;
		if (edge[i].w and dis[j] == dis[u] + 1) {
			tmp = dfs(j, min(res, edge[i].w));
			if (!tmp) dis[j] = INF;
			edge[i].w -= tmp;
			edge[i ^ 1].w += tmp;
			res -= tmp;
		}
	}
	return limit - res;
}

int main() {
	memset(head, -1, sizeof head);
	input(n), input(p), input(q); s = 0, t = p + n + n + q + 1;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= p; ++ j) {
			input(tmp);
			if (tmp) add(j, i + p, 1), add(i + p, j, 0);
		}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= q; ++ j) {
			input(tmp);
			if (tmp) add(i + p + n, j + p + n + n, 1), add(j + p + n + n, i + p + n, 0);
		}
	for (int i = 1; i <= n; ++ i)
		add(i + p, i + p + n, 1), add(i + p + n, i + p, 0);
	for (int i = 1; i <= p; ++ i) add(s, i, 1), add(i, s, 0);
	for (int i = 1; i <= q; ++ i) add(i + p + n + n, t, 1), add(t, i + p + n + n, 0);
	n = p + n + n + q + 1;
	while (bfs()) maxFlow += dfs(s, INF);
	cout << maxFlow << endl; 
	return 0;
}
