#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
#define DEBUG cerr << "-- DEBUG --\n";
using namespace std;
const int N = 1e5 + 10;
const int K = 20 + 10;
int n, m, a[N], mx, head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
int siz[N], fa[N], dep[N], hs[N], top[N];
int q[N], l, r, f[N][K], ans;
char op;

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

void dfs1(int u, int father, int depth) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == father) continue;
		dfs1(v, u, depth + 1), siz[u] += siz[v];
		if (siz[v] > siz[hs[u]]) hs[u] = v;
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	if (hs[u]) dfs2(hs[u], t);
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if (!top[v = edge[i].to]) dfs2(v, v);
}

int lca(int a, int b) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

void dp(int st, int ed) {
	int tmplca = lca(st, ed), ta = st, tb = ed;
	l = 0, r = dep[st] + dep[ed] - (dep[tmplca] << 1) + 1;
	while (st != tmplca) q[++ l] = st, st = fa[st];
	while (ed != tmplca) q[r --] = ed, ed = fa[ed];
	q[r] = tmplca, r = dep[ta] + dep[tb] - (dep[tmplca] << 1) + 1;
	memset(f, 0x3f, sizeof f), f[1][a[ta]] = 1;
	for (int i = 2; i <= r; ++ i) {
		for (int j = 0; j < mx; ++ j) 
			f[i][j] = min(f[i][j], f[i - 1][j + 1]);
		for (int j = 0; j < a[q[i]]; ++ j)
			f[i][a[q[i]]] = min(f[i][a[q[i]]], f[i][j] + 1);
	}
	ans = 0x3f3f3f3f;
	for (int i = 0; i <= mx; ++ i) ans = min(ans, f[r][i]);
}

int main() {
	rd(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= n; ++ i) rd(a[i]), mx = max(mx, a[i]);
	for (int i = 1, a, b; i < n; ++ i)
		rd(a), rd(b), add(a, b), add(b, a);
	dfs1(1, 0, 1), dfs2(1, 1), rd(m);
	for (int i = 1, s, t, u, x; i <= m; ++ i) {
		do op = getchar(); while (op != 'Q' and op != 'C');
		if (op == 'C') rd(u), rd(x), a[u] = x, mx = max(mx, x);
		if (op == 'Q') rd(s), rd(t), dp(s, t), ot(ans); 
	}
	return 0;
}
