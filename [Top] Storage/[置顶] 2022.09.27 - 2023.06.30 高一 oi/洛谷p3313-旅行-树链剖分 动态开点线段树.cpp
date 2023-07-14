#include <iostream>
#include <cstring>
#include <algorithm>

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
const int LOGN = 20;
int n, q, w[N], type[N];
string op; int x, y;
// bases 
int head[N << 1], idx;
struct Node {
	int nxt, to;
}edge[N << 1];
// grpah
int dep[N], siz[N], fa[N], hs[N];
int dfn[N], stamp, top[N];
int rt[N], tTol;
struct SegmentTree {
	int lson, rson, mx, sum;
	#define lson(x) tree[x].lson
	#define rson(x) tree[x].rson
	#define mx(x) tree[x].mx
	#define sum(x) tree[x].sum
}tree[N * LOGN << 1];
// Segment Tree

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int father, int depth) {
	dep[u] = depth, fa[u] = father, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs1(j, u, depth + 1);
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

void modify(int &u, int tl, int tr, int pos, int val) {
	if (!u) u = ++ tTol;
	mx(u) = max(mx(u), val), sum(u) += val;
	if (tl == tr) return;
	int mid = tl + tr >> 1;
	if (pos <= mid) modify(lson(u), tl, mid, pos, val);
	else modify(rson(u), mid + 1, tr, pos, val);
}

void del(int u, int tl, int tr, int pos) {
	if (tl == tr) return mx(u) = sum(u) = 0, void();
	int mid = tl + tr >> 1;
	if (pos <= mid) del(lson(u), tl, mid, pos);
	else del(rson(u), mid + 1, tr, pos);
	mx(u) = max(mx(lson(u)), mx(rson(u)));
	sum(u) = sum(lson(u)) + sum(rson(u));
	return;
}

int queryMax(int u, int tl, int tr, int l, int r) {
	if (tl >= l and tr <= r) return mx(u);
	int mid = tl + tr >> 1; int res = 0;
	if (l <= mid) res = max(res, queryMax(lson(u), tl, mid, l, r));
	if (r > mid) res = max(res, queryMax(rson(u), mid + 1, tr, l, r));
	return res;
}

int querySum(int u, int tl, int tr, int l, int r) {
	if (tl >= l and tr <= r) return sum(u);
	int mid = tl + tr >> 1; int res = 0;
	if (l <= mid) res += querySum(lson(u), tl, mid, l, r);
	if (r > mid) res += querySum(rson(u), mid + 1, tr, l, r);
	return res;
}

int queryPathMax(int root, int u, int v) {
	int res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		res = max(res, queryMax(root, 1, n, dfn[top[u]], dfn[u]));
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	res = max(res, queryMax(root, 1, n, dfn[v], dfn[u]));
	return res;
}

int queryPathSum(int root, int u, int v) {
	int res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		res += querySum(root, 1, n, dfn[top[u]], dfn[u]);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	res += querySum(root, 1, n, dfn[v], dfn[u]);
	return res;
}

int main() {
	input(n), input(q);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= n; ++ i) input(w[i]), input(type[i]);
	for (int i = 1, a, b; i < n; ++ i) {
		input(a), input(b);
		add(a, b), add(b, a);
	}
	dfs1(1, 0, 1); dfs2(1, 1);
	
	for (int i = 1; i <= n; ++ i) 
		modify(rt[type[i]], 1, n, dfn[i], w[i]);
	
	while (q --) {
		cin >> op; input(x), input(y);
		if (op == "CC") {
			del(rt[type[x]], 1, n, dfn[x]);
			modify(rt[y], 1, n, dfn[x], w[x]);
			type[x] = y;
		} 
		if (op == "CW") {
			del(rt[type[x]], 1, n, dfn[x]);
			modify(rt[type[x]], 1, n, dfn[x], y);
			w[x] = y;
		}
		if (op == "QS") output(queryPathSum(rt[type[x]], x, y));
		if (op == "QM") output(queryPathMax(rt[type[x]], x, y));
	}
	return 0;
}
