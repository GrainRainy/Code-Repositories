#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 2e6 + 10;
int n, m, head[N], etp;
struct Node { int nxt, to; }edge[M << 1];
int dfn[N], low[N], stk[N], top, stp, edcc;
vector<int> dcc[N];

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

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ stp, stk[++ top] = u;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if (!dfn[v = edge[i].to]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				edcc ++; int tmp;
				dcc[edcc].emplace_back(u);
				do {
					tmp = stk[top --];
					dcc[edcc].emplace_back(tmp);
				} while (tmp != v);
			}
		} else low[u] = min(low[u], dfn[v]);
	}
	if (!fa and !(~head[u])) dcc[++ edcc].emplace_back(u);
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i <= m; ++ i) {
		rd(a), rd(b);
		if (a != b) add(a, b), add(b, a);
	}
	for (int i = 1; i <= n; ++ i)
		if (!dfn[i]) tarjan(i, 0);
	ot(edcc);
	for (int i = 1; i <= edcc; ++ i) {
		ot(dcc[i].size(), ' ');
		for (auto t : dcc[i]) ot(t, ' ');
		putchar('\n');
	}
	return 0;
}
