#include <bits/stdc++.h>
#define __DEBUG__ puts("__DEBUG__");
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
const int M = 4e4 + 10;

int n, m, s, t, a, b, c, maxFlow, minCost;
int head[N], now[N], idx = 1;
struct Node { int nxt, to, f, c; } edge[M << 1];
int dis[N]; bool st[N];

inline void add(int a, int b, int f, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].f = f, edge[idx].c = c;
	edge[head[a] = idx].to = b;
}

bool spfa() {
	memset(st, 0, sizeof st);
	for (int i = 1; i <= n; ++ i) dis[i] = 0x3f3f3f3f;
	queue<int> q;
	q.push(s), dis[s] = 0, st[s] = true, now[s] = head[s];
	while (q.size()) {
		int u = q.front(); q.pop(); st[u] = false;
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (edge[i].f and dis[j] > dis[u] + edge[i].c) {
				dis[j] = dis[u] + edge[i].c;
				now[j] = head[j];
				if (!st[j]) q.push(j), st[j] = true;
			} 
		}
	}
	return dis[t] != INF;
}

int dfs(int u, int limit) {
	if (u == t) return limit;
	int tmp, res = limit;
	st[u] = true;
	for (int i = now[u], j; ~i; i = edge[i].nxt) {
		now[u] = i;
		j = edge[i].to;
		if (!st[j] and edge[i].f and dis[j] == dis[u] + edge[i].c) {
			tmp = dfs(j, min(res, edge[i].f));
			if (!tmp) dis[j] = INF;
			edge[i].f -= tmp;
			edge[i ^ 1].f += tmp;
			res -= tmp;
			minCost += edge[i].c * tmp;
		}
	}
	st[u] = false;
	return limit - res;
}

int main() {
	memset(head, -1, sizeof head);
	input(n), input(m); s = 1 + n, t = n;
	for (int i = 1; i <= m; ++ i) {
		input(a), input(b), input(c);
		add(a + n, b, 1, c), add(b, a + n, 0, -c);
	}
	for (int i = 1; i <= n; ++ i) 
		add(i, i + n, 1, 0), add(i + n, i, 0, 0);
	n <<= 1;
	while (spfa()) maxFlow += dfs(s, INF);
	cout << maxFlow << ' ' << minCost << endl;
	return 0;
}
