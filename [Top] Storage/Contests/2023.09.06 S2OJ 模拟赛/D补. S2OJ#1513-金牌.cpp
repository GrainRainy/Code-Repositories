#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

using namespace std;
using LL = long long;
const int N = 1e6 + 10;
const int MOD = 998244353;
int n, q, head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int siz[N], dep[N], fa[N], hs[N], top[N], dfn[N], node[N], stamp;
int p2[N] = {1}, f[N], g[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

inline int upd(const int &x) { return x + x >= MOD ? x + x - MOD : x + x; }
inline int upd(const int &x, const int &y) { return x + y >= MOD ? x + y - MOD : x + y; }

int qpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = (LL)a * a % MOD)
		if (b & 1) res = (LL)res * a % MOD;
	return res;
}

void dfs1(int u, int depth, int father) {
	f[u] = 1, siz[u] = 1, dep[u] = depth + 1, fa[u] = father;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs1(j, depth + 1, u);
		siz[u] += siz[j];
		f[u] = upd(f[u], upd(f[j], f[j]));
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int t) {
	top[u] = t, dfn[u] = ++ stamp, node[stamp] = u;
	if (!hs[u]) return;
	g[hs[u]] = upd(upd(g[u]), upd((f[u] + MOD - upd(f[hs[u]])) % MOD));
	dfs2(hs[u], t);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (top[j]) continue;
		g[j] = upd(upd(g[u]), upd((f[u] + MOD - upd(f[j])) % MOD));
		dfs2(j, j);
	}
}

int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

int kfa(int u, int k) {
	while (dfn[u] - dfn[top[u]] + 1 <= k) 
		k -= dfn[u] - dfn[top[u]] + 1, u = fa[top[u]];
	return node[dfn[u] - k];
}

int query(int x, int y) {
	int tlca = lca(x, y), dis = dep[x] + dep[y] - (dep[tlca] << 1);
	if (tlca == x or tlca == y) {
		if (tlca == y) swap(x, y);
		return ((LL)upd(g[x], f[x]) + MOD - upd(f[kfa(y, dis - 1)])) * f[y] % MOD * p2[dis] % MOD;
	} else return (LL)f[x] * f[y] % MOD * p2[dis] % MOD;
}

int main() {
	rd(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) {
		rd(a), rd(b), add(a, b), add(b, a);
		p2[i] = upd(p2[i - 1]);
	}
	p2[n] = upd(p2[n - 1]);
	dfs1(1, 1, 0), dfs2(1, 1);
	rd(q);
	for (int i = 1, x, y; i <= q; ++ i) rd(x), rd(y), ot(query(x, y));
	return 0;
}
