#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, now[N], dg[2][N], s = 1, sa, sb;
vector<int> g[N];
int stk[N << 1], top;

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

void dfs(int u) {
	for (int i = now[u]; i < g[u].size(); i = now[u])
		now[u] = i + 1, dfs(g[u][i]);
	stk[++ top] = u;
}

int main() {
	rd(n), rd(m);
	for (int i = 1, u, v; i <= m; ++ i) {
		rd(u), rd(v), g[u].push_back(v);
		dg[1][u] ++, dg[0][v] ++;
	}
	for (int i = 1; i <= n; ++ i) {
		sort(g[i].begin(), g[i].end());
		if (dg[1][i] == dg[0][i] + 1) s = i, sa ++;
		else if (dg[1][i] == dg[0][i] - 1) sb ++;
		else if (dg[1][i] == dg[0][i]) continue;
		else return puts("No"), 0;
	}
	if (sa and !(sa == sb and sb == 1)) return puts("No"), 0;
	dfs(s);
	while (top) ot(stk[top --], ' ');
	return putchar('\n'), 0;
}
