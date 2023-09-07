#include <bits/stdc++.h>
template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void ot(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

using namespace std;
const int N = 2e5 + 10;
int n, head[N], idx;
struct Node { int nxt, to; }edge[N];
bool st[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u) {
	if (st[u]) return;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		dfs(j);
	}
	if (u != 1) ot(u, ' '), st[u] = true;
}

int main() {
	rd(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, c, p; i <= n; ++ i) {
		rd(c);
		for (int j = 1; j <= c; ++ j)
			rd(p), add(i, p);
	}
	return dfs(1), 0;
}
