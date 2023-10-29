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

using IO::input;
using namespace std;
const int N = 1e3 + 10;
const int M = 1e5 + 10;
int n, m, ans;
int head[N], idx;
struct Node { int nxt, to; }edge[M << 1];
int col[N], dis[N], gp[N], mx[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

bool paint(int u, int c, int id) {
	col[u] = c, gp[u] = id;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!col[j] and !paint(j, 3 - c, id)) return false;
		else if (col[j] == c) return false;
	}
	return true;
}

void bfs(int st) {
	memset(dis, 0x3f, sizeof(int) * (n + 10));
	dis[st] = 0;
	queue<int> q; q.push(st);
	while (q.size()) {
		int u = q.front(); q.pop();
		mx[gp[u]] = max(mx[gp[u]], dis[u]);
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (dis[j] <= dis[u] + 1) continue;
			dis[j] = dis[u] + 1;
			q.push(j);
		}
	}
}

int main() {
	input(n), input(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i <= m; ++ i) {
		input(a), input(b);
		add(a, b), add(b, a);
	}
	for (int i = 1; i <= n; ++ i) 
		if (!col[i] and !paint(i, 1, ++ gp[0])) return puts("-1"), 0;
	for (int i = 1; i <= n; ++ i) bfs(i);
	for (int i = 1; i <= gp[0]; ++ i) ans += mx[i];
	return printf("%d\n", ans), 0;
}
