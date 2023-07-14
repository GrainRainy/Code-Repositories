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

const int N = 200 + 10;
const int M = N * N;
const int K = 10 * M;
const int INF = 0x3f3f3f3f;
const int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
const int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int n, m, s, t, x, y, ans;
int head[M], now[M], idx = 1;
struct Node { int nxt, to, w; } edge[K << 1];
// graph 
bool gph[N][N];
// bases 
int dis[M]; // Dinic 

inline int hsh(int x, int y) { return (x - 1) * n + y; }
inline bool check(int x, int y) { return x > 0 and x <= n and y > 0 and y <= n; }

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
		now[u] = i;
		j = edge[i].to;
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
	input(n), input(m), s = 0, t = n * n + 1;
	memset(head, -1, sizeof(int) * (n * n + 10));
	for (int i = 1; i <= m; ++ i) input(x), input(y), gph[x][y] = 1;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j) {
			if (gph[i][j]) continue;
			if ((i + j) & 1) {
				add(s, hsh(i, j), 1);
				add(hsh(i, j), s, 0);
				for (int k = 0, nx, ny; k < 8; ++ k) {
					nx = i + dx[k], ny = j + dy[k];
					if (check(nx, ny) and !gph[nx][ny]) {
						add(hsh(i, j), hsh(nx, ny), INF);
						add(hsh(nx, ny), hsh(i, j), 0);
					}
				}
			} else add(hsh(i, j), t, 1), add(t, hsh(i, j), 0);
		}
	ans = n * n - m; n = n * n + 1;
	while (bfs()) ans -= dfs(s, INF);
	cout << ans << endl;
	return 0;
}
