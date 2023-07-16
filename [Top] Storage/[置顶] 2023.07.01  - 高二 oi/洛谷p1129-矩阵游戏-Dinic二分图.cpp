#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x; 
	}
}

using IO::input;
using namespace std;
const int N = (200 + 10) << 1;
const int INF = 0x3f3f3f3f;
int n, s, t, maxFlow;
int head[N], now[N], idx = 1;
struct Node { int nxt, to, f; }edge[(N * N << 1) + (N << 2)];
int dis[N];

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].f = c;
	edge[head[a] = idx].to = b;
}

bool bfs() {
	memset(dis, 0x3f, sizeof(int) * ((n << 1) + 10));
	queue<int> q;
	q.push(s); dis[s] = 0; now[s] = head[s];
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (edge[i].f and dis[j] == INF) {
				dis[j] = dis[u] + 1;
				now[j] = head[j];
				q.push(j);
				if (j == t) return true;
			}
		}
	}
	return false;
}

int dinic(int u, int limit) {
	if (u == t) return limit;
	int res = limit;
	for (int i = now[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to, now[u] = i;
		if (edge[i].f and dis[j] == dis[u] + 1) {
			int delta = dinic(j, min(edge[i].f, res));
			if (!delta) dis[j] = INF;
			edge[i].f -= delta;
			edge[i ^ 1].f += delta;
			res -= delta;
		}
	}
	return limit - res;
}

void solve() {
	input(n);
	memset(head, -1, sizeof(int) * ((n << 1) + 10));
	maxFlow = 0, idx = 1;
	s = 0, t = (n << 1) + 1;
	for (int i = 1; i <= n; ++ i) {
		add(s, i, 1), add(i, s, 0);
		for (int j = 1, x; j <= n; ++ j) {
			input(x);
			if (x) add(i, j + n, 1), add(j + n, i, 0);
		}
	}
	for (int i = 1; i <= n; ++ i) add(i + n, t, 1), add(t, i + n, 0);
	while (bfs()) maxFlow += dinic(s, INF);
	if (maxFlow >= n) puts("Yes");
	else puts("No");
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
