#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		while (!isdigit(c)) c = getchar();
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
	template <typename T> inline void ot(T x, char ed = '\n') {
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
const int N = 1e3 + 10;
int n, m, head[2][N], idx[2];
struct Node { int nxt, to, w; }edge[2][N << 2];
struct Save { int a, b; }s[N << 1];
int dis[N], cnt[N];
bool st[N], av[N << 1];

inline void add(int a, int b, int c = 0, bool type = 0) {
	edge[type][++ idx[type]].nxt = head[type][a];
	edge[type][idx[type]].w = c;
	edge[type][head[type][a] = idx[type]].to = b;
}

bool dfs(int u) {
	if (u == n or st[u]) return true;
	for (int i = head[0][u], j; ~i; i = edge[0][i].nxt) {
		j = edge[0][i].to;
		if (av[i]) continue;
		av[i] = true;
		if (dfs(j)) add(u, j, 9, 1), add(j, u, -1, 1), st[u] = true;
	}
	return st[u];
}

bool spfa() {
	queue<int> q;
	for (int i = 1; i <= n; ++ i) q.push(i), st[i] = true;
	while (q.size()) {
		int u = q.front(); q.pop(), st[u] = false;
		for (int i = head[1][u], j; ~i; i = edge[1][i].nxt) {
			j = edge[1][i].to;
			if (dis[j] > dis[u] + edge[1][i].w) {
				dis[j] = dis[u] + edge[1][i].w;
				if (!st[j]) q.push(j), st[j] = true, cnt[j] ++;
				if (cnt[j] > n) return false;
			}
		}
	}
	return true;
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof head);
	for (int i = 1; i <= m; ++ i)
		rd(s[i].a), rd(s[i].b), add(s[i].a, s[i].b);
	if (!dfs(1) or !spfa()) return puts("-1"), 0;
	ot(n, ' '), ot(m);
	for (int i = 1; i <= m; ++ i) {
		ot(s[i].a, ' '), ot(s[i].b, ' ');
		if (dis[s[i].b] - dis[s[i].a] >= 1 and dis[s[i].b] - dis[s[i].a] <= 9)
			ot(dis[s[i].b] - dis[s[i].a]);
		else puts("1");
	}
	return 0;
}
