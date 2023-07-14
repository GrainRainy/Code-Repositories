#include <bits/stdc++.h>
#define lson (u << 1)
#define rson (u << 1 | 1)
#define debug(x) cout << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;

const int N = 1e5 + 10;
int n, m, op, a, b;
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
// bases 
int siz[N], fa[N], dep[N], hs[N];
int dfn[N], stamp, top[N];
// decomposition 
struct Tree {
	int lcol, rcol, cnt, tag;
	#define lcol(u) tree[u].lcol
	#define rcol(u) tree[u].rcol
	#define cnt(u) tree[u].cnt
	#define tag(u) tree[u].tag
}tree[N << 2];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int depth, int father) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs1(j, depth + 1, u);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	dfn[u] = ++ stamp, top[u] = Top;
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

Tree merge(Tree a, Tree b) {
	return {a.lcol, b.rcol, a.cnt + b.cnt + (a.rcol == b.lcol)};
} 

void pushDown(int u, int tl, int tr) {
	if (!tag(u)) return;
	lcol(lson) = rcol(lson) = lcol(rson) = rcol(rson) = tag(u);
	tag(lson) = tag(rson) = tag(u);
	int mid = tl + tr >> 1;
	cnt(lson) = mid - tl, cnt(rson) = tr - mid - 1;
	tag(u) = 0;
}

void build(int u, int tl, int tr) {
	if (tl == tr) return tree[u] = {tl, tl, 0, 0}, void();
	int mid = tl + tr >> 1;
	build(lson, tl, mid), build(rson, mid + 1, tr);
	tree[u] = merge(tree[lson], tree[rson]);
}

void modify(int u, int tl, int tr, int l, int r, int color) {
	if (tl >= l and tr <= r) return tree[u] = {color, color, tr - tl, color}, void();
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	if (l <= mid) modify(lson, tl, mid, l, r, color);
	if (r > mid) modify(rson, mid + 1, tr, l, r, color);
	tree[u] = merge(tree[lson], tree[rson]);
}

Tree query(int u, int tl, int tr, int l, int r) {
	if (tl >= l and tr <= r) return tree[u];
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	if (r <= mid) return query(lson, tl, mid, l, r);
	if (l > mid) return query(rson, mid + 1, tr, l, r);
	return merge(query(lson, tl, mid, l, r), query(rson, mid + 1, tr, l, r));
}

int lca(int u, int v) {
	while (top[u] ^ top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	} 
	return (dep[u] < dep[v]) ? u : v;
}

void modifyPath(int u, int v, int col) {
	while (top[u] ^ top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		modify(1, 1, n, dfn[top[u]], dfn[u], col);
		u = fa[top[u]]; 
	}
	if (dep[u] < dep[v]) swap(u, v);
	modify(1, 1, n, dfn[v], dfn[u], col);
}

int queryPath(int u, int v) {
	Tree res1= {0, 0, 0, 0}, res2 = {0, 0, 0, 0};
	int tlca = lca(u, v);
	while (top[u] ^ top[tlca]) {
		res1 = merge(query(1, 1, n, dfn[top[u]], dfn[u]), res1);
		u = fa[top[u]];
	}
	res1 = merge(query(1, 1, n, dfn[tlca], dfn[u]), res1);
	while (top[v] ^ top[tlca]) {
		res2 = merge(query(1, 1, n, dfn[top[v]], dfn[v]), res2);
		v = fa[top[v]];
	}
	res2 = merge(query(1, 1, n, dfn[tlca], dfn[v]), res2);
	return res1.cnt + res2.cnt;
}

void solve() {
	input(n), input(m);
	stamp = idx = 0;
	memset(head, -1, sizeof(int) * (n + 10)); 
	memset(top, 0, sizeof(int) * (n + 10));
	memset(siz, 0, sizeof(int) * (n + 10));
	memset(hs, 0, sizeof(int) * (n + 10));
	for (int i = 1; i < n; ++ i) {
		input(a), input(b);
		add(a, b), add(b, a);
	}
	dfs1(1, 1, 0), dfs2(1, 1);
	build(1, 1, n); 
	for (int i = 1; i <= m; ++ i) {
		input(op), input(a), input(b);
		if (op == 1) modifyPath(a, b, i + n);
		if (op == 2) output(queryPath(a, b));
	}
}

int main() {
	freopen("edge.in", "r", stdin);
	freopen("edge.out", "w", stdout);
	int t; input(t);
	while (t --) solve();
	return 0;
}
