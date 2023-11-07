#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, rt, w[N], head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
int mn[N], siz[N], ans[N];

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

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void dfs(int u, int fa) {
	mn[u] = w[u], siz[u] = 1;
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if ((v = edge[i].to) != fa)
			dfs(v, u), mn[u] = min(mn[u], mn[v]), siz[u] += siz[v];
	if (u == rt) for (int i = head[u]; ~i; i = edge[i].nxt)
		ans[0] = max(ans[0], siz[edge[i].to]);
	else if (mn[u] == w[u]) ans[w[u]] = n - siz[u];
}

int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) 
		head[i] = -1, rd(w[i]), rt = !w[i] ? i : rt;
	for (int i = 2, fa; i <= n; ++ i)
		rd(fa), add(fa, i), add(i, fa);
	dfs(rt, 0);
	for (int i = 0; i < n; ++ i) ot(ans[i], ' ');
	return cout << n << '\n', 0;
}
