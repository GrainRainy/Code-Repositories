#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1.5e2 + 10;
const int M = 6e3 + 10;
int n, m, s, t, pre[N], head[N << 1], etp = 1;
struct Node { int nxt, pre, to, w; }e[(M << 1) + (N << 2)];
int dis[N << 1], now[N << 1], ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b, int w) {
	e[++ etp] = {head[a], a, b, w};
	head[a] = etp;
}

bool bfs() {
	queue<int> q;
	memset(dis, 0x3f, sizeof(int) * ((n << 1) + 10));
	q.push(s), dis[s] = 0, now[s] = head[s];
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = head[u], v; ~i; i = e[i].nxt)
			if (dis[v = e[i].to] == 0x3f3f3f3f and e[i].w) {
				q.push(v), dis[v] = dis[u] + 1, now[v] = head[v];
				if (v == t) return true;
			}
	}
	return false;
}

int dfs(int u, int lim) {
	if (u == t) return lim;
	int tmp, res = lim;
	for (int i = now[u], v; ~i and res; i = e[i].nxt) {
		now[u] = i, v = e[i].to;
		if (dis[v] == dis[u] + 1 and e[i].w) {
			tmp = dfs(v, min(res, e[i].w));
			if (!tmp) dis[v] = 0x3f3f3f3f;
			e[i].w -= tmp, e[i ^ 1].w += tmp;
			res -= tmp;
		}
	}
	return lim - res;
}

void ot(int u) {
	cout << u << ' ';
	for (int i = head[u], v; ~i; i = e[i].nxt)
		if (!e[i].w and (v = e[i].to) > n and v < t) ot(v - n);
}

int main() {
	cout.tie(0)->sync_with_stdio(false);
	rd(n), rd(m), ans = n, s = 0, t = (n << 1) + 1;
	memset(head, -1, sizeof(int) * ((n << 1) + 10));
	for (int i = 1; i <= n; ++ i) {
		add(s, i, 1), add(i, s, 0);
		add(i + n, t, 1), add(t, i + n, 0);
	}
	for (int i = 1, a, b; i <= m; ++ i)
		rd(a), rd(b), add(a, b + n, 1), add(b + n, a, 0);
	while (bfs()) ans -= dfs(s, 0x3f3f3f3f);
	for (int i = 2; i <= etp; ++ i)
		if (!e[i].w and e[i].pre > s and e[i].pre <= n)
			if (e[i].to > n and e[i].to < t) pre[e[i].to - n] = e[i].pre;
	for (int i = 1; i <= n; ++ i) if (!pre[i]) ot(i), cout << '\n';
	return cout << ans << '\n', 0;
}
