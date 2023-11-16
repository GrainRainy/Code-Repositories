#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 3e5 + 10;
const int LN = 20 + 5;
int n, m, mx, head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
int fa[N][LN], dep[N], siz[N], hs[N];
int top[N], dfn[N], stp;
struct SegmentTree {
	int mx, tg;
	#define l(x) ((x) << 1)
	#define r(x) ((x) << 1 | 1)
	#define mx(x) tree[x].mx
	#define tg(x) tree[x].tg
}tree[N << 2];

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void dfs1(int u, int father, int depth) {
	fa[u][0] = father, dep[u] = depth, siz[u] = 1;
	for (int i = 1; i <= mx; ++ i)
		fa[u][i] = fa[fa[u][i - 1]][i - 1]; 
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == father) continue;
		dfs1(v, u, depth + 1);
		siz[u] += siz[v];
		if (siz[v] > siz[hs[u]]) hs[u] = v;
	}
}

void dfs2(int u, int t) {
	top[u] = t, dfn[u] = ++ stp;
	if (hs[u]) dfs2(hs[u], t);
	for (int i = head[u], v; ~i; i = edge[i].nxt) 
		if (!top[v = edge[i].to]) dfs2(v, v);
}

int lca(int a, int b) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]][0];
	}
	return dep[a] < dep[b] ? a : b;
}

void pushdown(int u) {
	mx(l(u)) += tg(u), mx(r(u)) += tg(u);
	tg(l(u)) += tg(u), tg(r(u)) += tg(u);
	tg(u) = 0;
}

void mfy(int u, int tl, int tr, int l, int r, int v) {
	if (l <= tl and tr <= r) return mx(u) += v, tg(u) += v, void();
	int mid = tl + tr >> 1;
	if (tg(u)) pushdown(u);
	if (l <= mid) mfy(l(u), tl, mid, l, r, v);
	if (r > mid) mfy(r(u), mid + 1, tr, l, r, v);
	mx(u) = max(mx(l(u)), mx(r(u)));
}

void sol(int a, int b) {
	if (a == b) return mfy(1, 1, n, 1, n, 1);
	mfy(1, 1, n, 1, n, 2);
	int l = lca(a, b);
	if (l == b) swap(a, b);
	if (l == a) {
		int p = b;
		for (int i = mx; ~i; -- i) if (dep[fa[p][i]] > dep[a]) p = fa[p][i];
		mfy(1, 1, n, dfn[p], dfn[p] + siz[p] - 1, -1);
		mfy(1, 1, n, 1, n, -1), mfy(1, 1, n, dfn[b], dfn[b] + siz[b] - 1, 1);
	} else {
		mfy(1, 1, n, 1, n, -1), mfy(1, 1, n, dfn[a], dfn[a] + siz[a] - 1, 1);
		mfy(1, 1, n, 1, n, -1), mfy(1, 1, n, dfn[b], dfn[b] + siz[b] - 1, 1);
	}
}

int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m, mx = log2(n);
	memset(head, -1, sizeof head);
	for (int i = 1, a, b; i < n; ++ i)
		cin >> a >> b, add(a, b), add(b, a);
	dfs1(1, 0, 1), dfs2(1, 1);
	for (int i = 1, x, y; i <= m; ++ i)
		cin >> x >> y, sol(x, y), cout << mx(1) << '\n';
	return 0;
}
