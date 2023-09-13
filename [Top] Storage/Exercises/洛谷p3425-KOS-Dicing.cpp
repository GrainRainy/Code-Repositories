#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, m, head[N << 1], idx = 1, sm[N], mx;
struct Node { int nxt, to; }edge[N << 2];
bitset<N << 1> vis;
bitset<N << 2> st;

template <typename T> inline void rd(T &x, char ed = '\n') {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

bool dfs(int u) {
	if (u <= n and sm[u] < mx) return sm[u] ++, true;
	vis[u] = true;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!vis[j] and st[i] and dfs(j))
			return st[i] = 0, st[i ^ 1] = 1, true;
	}
	return false;
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * (n + m + 10));
	for (int i = 1, a, b; i <= m; ++ i) {
		rd(a), rd(b);
		add(i + n, a), st[idx] = true, add(a, i + n);
		add(i + n, b), st[idx] = true, add(b, i + n);
		vis.reset();
		if (!dfs(n + i)) mx ++, vis.reset(), dfs(n + i);
	}
	cout << mx << '\n';
	for (int i = 1; i <= m; ++ i) putchar('0' + st[head[n + i]]), putchar('\n');
	return 0;
}
