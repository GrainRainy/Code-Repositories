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
const int N = 1e3 + 10;
const int M = 1e4 + 10;

int n, m, k, s, t, tmp;
int head[N], now[N], idx = 1;
struct Node { int nxt, to, f, c; }edge[M << 1];
int dis[N]; bool st[N];
struct Save { int a, b, c, d; }save[M];
int ans1, ans2;

inline void add(int a, int b, int f, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].f = f, edge[idx].c = c;
	edge[head[a] = idx].to = b;
}

bool spfa() {
	memset(st, 0, sizeof(int) * (n + 10));
	for (int i = 0; i <= n; ++ i) dis[i] = INF;
	queue<int> q;
	q.push(s), dis[s] = true, now[s] = head[s];
	while (q.size()) {
		int u = q.front(); q.pop(); st[u] = false;
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (edge[i].f and dis[j] > dis[u] + edge[i].c) {
				dis[j] = dis[u] + edge[i].c;
				if (!st[j]) q.push(j), now[j] = head[j];
			}
		}
	}
	return dis[t] != INF;
}

int dfs(int u, int limit) {
	if (u == t) return limit;
	int tmp, res = limit;
	st[u] = true;
	for (int i = now[u], j; ~i and res; i = edge[i].nxt) {
		now[u] = i;
		j = edge[i].to;
		if (!st[j] and edge[i].f and dis[j] == dis[u] + edge[i].c) {
			tmp = dfs(j, min(res, edge[i].f));
			if (!k) dis[j] = INF;
			edge[i].f -= tmp;
			edge[i ^ 1].f += tmp;
			res -= tmp;
			ans2 += edge[i].c * tmp;
		}
	}
	st[u] = false;
	return limit - res;
}

int main() {
	input(n), input(m), input(k);
	memset(head, -1, sizeof head);
	s = 1, t = n;
	for (int i = 1, u, v, c, w; i <= m; ++ i) {
		input(u), input(v), input(c), input(w);
		add(u, v, c, 0), add(v, u, 0, 0);
		save[i] = {u, v, c, w};
	}
	int flow = 0;
	while (spfa()) while(flow = dfs(s, INF)) ans1 += flow;
	s = 0, add(s, 1, k, 0), add(1, s, 0, 0);
	for (int i = 1, u, v, w; i <= m; ++ i) {
		u = save[i].a, v = save[i].b, w = save[i].d;
		add(u, v, INF, w), add(v, u, 0, -w);
	}
	while (spfa()) while (flow = dfs(s, INF));
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}
