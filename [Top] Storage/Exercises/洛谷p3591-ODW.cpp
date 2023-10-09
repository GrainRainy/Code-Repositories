#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
const int LOGN = 17;
const int SQRTN = 225;
int n, gap, lgn, w[N], p[N], c[N], head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int fa[N][LOGN + 5], dep[N], mxl[N], ls[N], top[N];
vector<int> up[N], dn[N];
int sum[N][SQRTN + 10];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u) {
	dep[u] = dep[fa[u][0]] + 1, mxl[u] = 1;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == fa[u][0]) continue;
		fa[v][0] = u;
		for (int j = 0; fa[v][j]; ++ j) fa[v][j + 1] = fa[fa[v][j]][j];
		dfs1(v);
		if (mxl[v] + 1 > mxl[u]) mxl[u] = mxl[v] + 1, ls[u] = v; 
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	for (int i = 1, p = fa[u][0]; i <= gap; ++ i, p = fa[p][0])
		sum[u][i] = sum[p][i] + w[u];
	if (u == t) {
		for (int i = 1, p = u; i <= mxl[u]; ++ i)
			up[u].emplace_back(p), p = fa[p][0];
		for (int i = 1, p = u; i <= mxl[u]; ++ i)
			dn[u].emplace_back(p), p = ls[p];
	}
	if (!ls[u]) return;
	dfs2(ls[u], t);
	for (int i = head[u], v; ~i; i = edge[i].nxt) 
		if (!top[v = edge[i].to]) dfs2(v, v);
}

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int i = lgn; ~i; -- i) if (dep[fa[a][i]] >= dep[b]) a = fa[a][i];
	if (a == b) return b;
	for (int i = lgn; ~i; -- i)
		if (fa[a][i] != fa[b][i]) a = fa[a][i], b = fa[b][i];
	return fa[a][0];
}

int kfa(int u, int k) {
	if (!k) return u;
	if (dep[u] <= k) return 0;
	u = fa[u][(int)log2(k)], k -= 1 << (int)log2(k);
	k -= dep[u] - dep[top[u]], u = top[u];
	return k < 0 ? dn[u][-k] : up[u][k];
}

int main() {
	rd(n), lgn = log2(n), gap = sqrt(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= n; ++ i) rd(w[i]);
	for (int i = 1, a, b; i < n; ++ i)
		rd(a), rd(b), add(a, b), add(b, a);
	for (int i = 1; i <= n; ++ i) rd(p[i]);
	dfs1(1), dfs2(1, 1);
	for (int i = 2, a, b, c, l; i <= n; ++ i) {
		a = p[i - 1], b = p[i], rd(c), l = lca(a, b);
		if (c <= gap) {
			int resa = sum[a][c] - sum[kfa(a, ((dep[a] - dep[l]) / c + 1) * c)][c];
			int resb = sum[b][c] - sum[kfa(b, ceil((dep[b] - dep[l]) * 1.0 / c) * c)][c];
			ot(resa + resb);
		} else {
			int res = 0;
			while (dep[a] >= dep[l]) {
				res += w[a], a = kfa(a, c);
			}
			while (dep[b] > dep[l]) res += w[b], b = kfa(b, c);
			ot(res);
		}
	}
	return 0;
}
