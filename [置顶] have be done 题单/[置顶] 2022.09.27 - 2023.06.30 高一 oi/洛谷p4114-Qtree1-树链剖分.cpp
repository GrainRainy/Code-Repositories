#include <iostream>
#include <cstring>

#define __DEBUG__ puts("__DEBUG__");

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
using PII = pair<int, int>;

const int N = 1e5 + 10;
int n, x, y; string op;
PII q[N];
int head[N], idx;
struct Node { int nxt, to, w; } edge[N << 1];
// graph
int dep[N], fa[N], hs[N], w[N], siz[N];
int dfn[N], stamp, top[N], nw[N];
// Tree Partitions 
int root, tTol;
struct SegmentTree {
	int lson, rson, mx;
	#define lson(u) tree[u].lson
	#define rson(u) tree[u].rson
	#define mx(u) tree[u].mx
}tree[N << 1];

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int depth, int father) {
	dep[u] = depth, fa[u] = father, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		w[j] = edge[i].w;
		dfs1(j, depth + 1, u);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	dfn[u] = ++ stamp, nw[stamp] = w[u], top[u] = Top;
	if (hs[u]) dfs2(hs[u], Top);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

void pushUp(int u) {
	if (!lson(u)) mx(u) = mx(rson(u));
	if (!rson(u)) mx(u) = mx(lson(u));
	else mx(u) = max(mx(lson(u)), mx(rson(u)));
}

void modify(int &u, int tl, int tr, int pos, int val) {
	if (!u) u = ++ tTol;
	if (tl == tr) {	mx(u) = val; return; }
	int mid = tl + tr >> 1;
	if (pos <= mid) modify(lson(u), tl, mid, pos, val);
	else modify(rson(u), mid + 1, tr, pos, val);
	pushUp(u);
}

int query(int u, int tl, int tr, int l, int r) {
	if (tl >= l and tr <= r) return mx(u);
	int mid = tl + tr >> 1, res = 0;
	if (l <= mid) res = max(res, query(lson(u), tl, mid, l, r));
	if (r > mid) res = max(res, query(rson(u), mid + 1, tr, l, r));
	return res;
}

int queryPath(int a, int b) {
	int res = 0;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		res = max(res, query(root, 1, n, dfn[top[a]], dfn[a]));
		a = fa[top[a]];
	}
	if (dep[a] < dep[b]) swap(a, b);
	res = max(res, query(root, 1, n, dfn[b] + 1, dfn[a]));
	return res;
}

void print(int u, int tl, int tr) {
	cout << u << ' ' << tl << ' ' << tr << ' ' << mx(u);
	cout << ' ' << lson(u) << ' ' << rson(u) << endl;
	int mid = tl + tr >> 1;
	if (lson(u)) print(lson(u), tl, mid);
	if (rson(u)) print(rson(u), mid + 1, tr);
}

int getdot(int x) {
	if (dep[q[x].first] > dep[q[x].second]) swap(q[x].first, q[x].second);
	return dfn[q[x].second];
}

int main() {
	input(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b, w; i < n; ++ i) {
		input(a), input(b), input(w);
		add(a, b, w), add(b, a, w);
		q[i].first = a, q[i].second = b;
	}
	dfs1(1, 1, 0);
	dfs2(1, 1);
	for (int i = 1; i <= n; ++ i) modify(root, 1, n, i, nw[i]);
	while (cin >> op and op != "DONE") {
		input(x), input(y);
		if (op == "QUERY") output(queryPath(x, y));
		if (op == "CHANGE") modify(root, 1, n, getdot(x), y);
	}
//	print(1, 1, n);
	return 0;
}
