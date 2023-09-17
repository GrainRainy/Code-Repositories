#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, m, head[N], idx;
struct Node { int nxt, to; }edge[N];
int dfn[N], low[N], id[N], stk[N], top, stamp, cntScc;
bool st[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++ stamp;
	stk[++ top] = u, st[u] = true;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!dfn[j]) tarjan(j), low[u] = min(low[u], low[j]);
		else if (st[j]) low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u]) {
		cntScc ++;
		do {
			u = stk[top --], st[u] = false;
			id[u] = cntScc;
		} while (dfn[u] != low[u]);
	}
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * ((n << 1) + 10));
	for (int i = 1, a, b, c, d; i <= m; ++ i) {
		rd(a), rd(b), rd(c), rd(d);
		add(a + n * b, c + n * (d ^ 1));
		add(c + n * d, a + n * (b ^ 1));
	}
	for (int i = 1; i <= n << 1; ++ i) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; ++ i)
		if (id[i] == id[i + n]) return puts("IMPOSSIBLE") & 0;
	puts("POSSIBLE");
	for (int i = 1; i <= n; ++ i) putchar('0' + (id[i] < id[i + n])), putchar(' ');
	return putchar('\n'), 0;
}
