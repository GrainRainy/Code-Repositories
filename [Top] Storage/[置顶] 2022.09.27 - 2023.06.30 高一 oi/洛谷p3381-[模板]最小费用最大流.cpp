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
const int N = 5e3 + 10;
const int M = 5e4 + 10;
int n, m, s, t, u, v, w, c, maxFlow, minCost;
// bases 
int head[N], now[N], idx = 1;
struct Node { int nxt, to, w, c; }edge[M << 1];
// graph 
int dis[N]; bool st[N];
// spfa 

inline void add(int a, int b, int w, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w, edge[idx].c = c;
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
			if (edge[i].w and dis[j] > dis[u] + edge[i].c) {
				dis[j] = dis[u] + edge[i].c;
				now[j] = head[j];
				if (!st[j]) q.push(j), st[j] = true;
			}
		}
	}
	return dis[t] != INF;
}

int dfs(int u, int flow) {
	if (u == t) return flow;
	int k, res = flow;
	st[u] = true;
	for (int i = now[u], j; ~i and res; i = edge[i].nxt) {
		now[u] = i;
		j = edge[i].to;
		if (!st[j] and edge[i].w and dis[j] == dis[u] + edge[i].c) {
			k = dfs(j, min(res, edge[i].w));
			if (!k) dis[j] = INF;
			edge[i].w -= k;
			edge[i ^ 1].w += k;
			res -= k;
			minCost += edge[i].c * k;
		}
	}
	st[u] = false; 
	return flow - res;
}

int main() {
	memset(head, -1, sizeof head);
	input(n), input(m), input(s), input(t);
	for (int i = 1; i <= m; ++ i) {
		input(u), input(v), input(w), input(c);
		add(u, v, w, c), add(v, u, 0, -c);
	}
	while (spfa()) maxFlow += dfs(s, INF);
	cout << maxFlow << ' ' << minCost << endl;
	return 0;
}
