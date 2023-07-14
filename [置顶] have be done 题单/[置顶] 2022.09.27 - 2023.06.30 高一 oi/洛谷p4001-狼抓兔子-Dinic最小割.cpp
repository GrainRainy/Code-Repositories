#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0l; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
 	} 
}

using namespace IO;
using namespace std;

const int N = 1e3 + 10;
const int M = 3 * N * N;
const int INF = 0x3f3f3f3f;
int n, m, s, t, maxFlow, tmp;
int head[N * N], now[N * N], idx = 1;
struct Node { int nxt, to, w; } edge[M << 1];
int dis[N * N];

inline int hsh(int x, int y) { return (x - 1) * m + y; }
inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

bool bfs() {
	for (int i = 1; i <= n; ++ i) dis[i] = INF;
	queue<int> q;
	q.push(s), dis[s] = 0, now[s] = head[s];
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (edge[i].w and dis[j] == INF) {
				q.push(j), dis[j] = dis[u] + 1, now[j] = head[j];
				if (j == t) return true;
			}
		}
	}
	return false;
}

int dfs(int u, int limit) {
	if (u == t) return limit;
	int tmp, res = limit;
	for (int i = now[u], j; ~i and res; i = edge[i].nxt) {
		now[u] = i; j = edge[i].to;
		if (edge[i].w and (dis[j] == dis[u] + 1)) {
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
	input(n), input(m); s = 1, t = n * m;
	memset(head, -1, sizeof(int) * (n * m + 10));
	for (int i = 1; i <= n; ++ i) 
		for (int j = 1; j < m; ++ j) 
			input(tmp), add(hsh(i, j), hsh(i, j + 1), tmp), add(hsh(i, j + 1), hsh(i, j), tmp);
	for (int i = 1; i < n; ++ i)
		for (int j = 1; j <= m; ++ j)
			input(tmp), add(hsh(i, j), hsh(i + 1, j), tmp), add(hsh(i + 1, j), hsh(i, j), tmp);
	for (int i = 1; i < n; ++ i)
		for (int j = 1; j < m; ++ j)
			input(tmp), add(hsh(i, j), hsh(i + 1, j + 1), tmp), add(hsh(i + 1, j + 1), hsh(i, j), tmp);
	n = n * m;
	while (bfs()) maxFlow += dfs(s, INF);
	cout << maxFlow << endl;
	return 0;
}
