#include <bits/stdc++.h>
#define DEBUG cerr << "--- DEBUG ---\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f = (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void ot(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[30], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

using namespace std;
using LL = long long;
const int N = 1e6 + 10;
const int MOD = 998244353;
int n, q, head[N], idx, q2[N] = {1}, rt;
struct Node { int nxt, to; }edge[N << 1];
int siz[N], hs[N], dep[N], fa[N], top[N];
int nd[N], sum[N];
int qx, qy;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

void dfs1(int u, int depth, int father) {
	siz[u] = 1, fa[u] = father, dep[u] = depth;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs1(j, depth + 1, u);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	if (!hs[u]) return;
	dfs2(hs[u], t);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

int lca(int a, int b) {
	while (top[a] ^ top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

inline int upd(const int &x, const int &y) {
	return x + y > MOD ? x + y - MOD : x + y;
}

void dp(int u, int depth, int father) {
	sum[u] = upd(sum[u], q2[depth]);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dp(j, depth + 1, u);
	}
}

int query() {
	int tlca = lca(qx, qy);
	int dis = dep[qx] + dep[qy] - dep[tlca] * 2;
	dp(tlca, 1, 0);
	if (tlca == qx) {
		sum[qx] = upd(sum[qx], MOD - sum[qy]);
		sum[qy] *= qpow(q2[dis], MOD - 2);
	} else if (tlca == qy) {
		sum[qy] = upd(sum[qy], MOD - sum[qx]);
		sum[qx] *= qpow(q2[dis], MOD - 2);
	}

	for (int i = 1; i <= n; ++ i) cout << sum[i] << ' ';
	cout << '\n';
	
	return (LL)q2[dis] * sum[qx] % MOD * sum[qy] % MOD;
}

int main() {
	rd(n);
	memset(head, -1, sizeof head);
	for (int i = 1, x, y; i < n; ++ i) {
		rd(x), rd(y);
		add(x, y), add(y, x);
		q2[i] = upd(q2[i - 1], q2[i - 1]);
	}
	dfs1(1, 1, 0);
	dfs2(1, 1);
	rd(q);
	for (int i = 1; i <= q; ++ i)
		rd(qx), rd(qy), ot(query());
	return 0;
}
