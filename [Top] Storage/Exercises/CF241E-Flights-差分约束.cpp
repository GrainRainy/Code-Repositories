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
const int M = 5e3 + 10;
int n, m, head[2][N], idx[2];
struct Node { int nxt, to, w; }edge[2][M << 1];
struct Save { int a, b; }s[M];
int dis[N], cnt[N];
bool st[N], av[M];

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
		if (dfs(j)) add(u, j, 2, 1), add(j, u, -1, 1), st[u] = true;
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
	if (!dfs(1) or !spfa()) return puts("No"), 0;
	puts("Yes");
	for (int i = 1; i <= m; ++ i) {
		if (dis[s[i].b] - dis[s[i].a] >= 1 and dis[s[i].b] - dis[s[i].a] <= 2)
			ot(dis[s[i].b] - dis[s[i].a]);
		else puts("1");
	}
	return 0;
}
