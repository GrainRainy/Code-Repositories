#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, head[N], idx, ans[N];
struct Node { int nxt, to, id; }edge[N << 1];
struct Edge { int a, b, c; }e[N];
int dep[N], fa[N], id[N], p[N];
int stk[N], top, pos;

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

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].id = c;
	edge[head[a] = idx].to = b;
}

void dfs(int u, int father, int depth) {
	fa[u] = father, dep[u] = depth;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		id[j] = edge[i].id;
		dfs(j, u, depth + 1);
	}
}

void qpath(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	if (dep[a] < dep[b]) swap(a, b);
	stk[++ top] = id[a];
	p[a] = find(fa[a]);
	qpath(a, b);
}

void calc(int a, int b) {
	top = 0;
	qpath(a, b);
	sort(stk + 1, stk + top + 1);
	for (int i = 1; i <= top; ++ i) if (stk[i] > 0) ans[stk[i]] = ++ pos;
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= m; ++ i) {
		p[i] = i;
		rd(e[i].a), rd(e[i].b), rd(e[i].c);
		if (e[i].c) add(e[i].a, e[i].b, i), add(e[i].b, e[i].a, i);
	}
	if (m < n) p[n] = n;
	dfs(1, 1, 1);
	for (int i = 1; i <= m; ++ i) {
		if (ans[i]) continue;
		calc(e[i].a, e[i].b);
		if (!e[i].c) ans[i] = ++ pos;
	}
	for (int i = 1; i <= m; ++ i) ot(ans[i], " \n"[i == m]);
	return 0;
}
