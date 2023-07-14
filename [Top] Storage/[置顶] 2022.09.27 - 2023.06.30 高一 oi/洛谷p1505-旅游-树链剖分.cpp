#include <iostream>
#include <cstring>
#include <algorithm>

#define lson(u) ((u) << 1) 
#define rson(u) ((u) << 1 | 1)

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int n, m, u, v, w;
string op;
struct Saving {
	int u, v;
}se[N];
// basis
int head[N], idx;
struct Node {
	int nxt, to, w;
}edge[N << 1];
// graph
struct SegmentTree {
	int l, r;
	int sum, tag;
	int max, min;

	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define tag(x) tree[x].tag
	#define mx(x) tree[x].max
	#define mn(x) tree[x].min
}tree[N << 2];
// Segment Tree
int siz[N], fa[N], dep[N], hs[N], tw[N];
int stamp, dfn[N], top[N], nw[N];
// cuttings 

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int depth, int father) {
	dep[u] = depth, fa[u] = father, siz[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == father) continue;
		dfs1(j, depth + 1, u);
		tw[j] = edge[i].w;
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	dfn[u] = ++ stamp, top[u] = Top, nw[stamp] = tw[u];
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == fa[u] or j == hs[u]) continue;
		dfs2(j, j);
	}
}

inline void PushUp(int u) {
	sum(u) = sum(lson(u)) + sum(rson(u));
	mn(u) = min(mn(lson(u)), mn(rson(u)));
	mx(u) = max(mx(lson(u)), mx(rson(u)));
	return;
}

void PushDown(int u) {
	if (!tag(u)) return;
	tag(lson(u)) ^= 1, tag(rson(u)) ^= 1;
	sum(lson(u)) *= -1, sum(rson(u)) *= -1;
	mx(lson(u)) *= -1, mx(rson(u)) *= -1;
	mn(lson(u)) *= -1, mn(rson(u)) *= -1;
	swap(mx(lson(u)), mn(lson(u)));
	swap(mx(rson(u)), mn(rson(u)));
	tag(u) = 0;
}

void build(int u, int l, int r) {
	tree[u] = {l, r, nw[l], 0, nw[l], nw[l]};
	if (l == r) return;
	int mid = l + r >> 1;
	build(lson(u), l, mid), build(rson(u), mid + 1, r);
	PushUp(u);
}

void ChangePaN(int u, int l, int r) {
	if (l > r(u) or r < l(u)) return;
	if (l <= l(u) and r >= r(u)) {
		sum(u) *= -1, mn(u) *= -1, mx(u) *= -1;
		swap(mn(u), mx(u));
		tag(u) ^= 1;
		return;
	} 
	PushDown(u);
	ChangePaN(lson(u), l, r), ChangePaN(rson(u), l, r);
	PushUp(u);
}

void ChangeVal(int u, int l, int r, int val) {
	if (l > r(u) or r < l(u)) return;
	if (l == l(u) and r == r(u)) {
		sum(u) = mn(u) = mx(u) = val;
		return;
	}
	PushDown(u);
	ChangeVal(lson(u), l, r, val), ChangeVal(rson(u), l, r, val);
	PushUp(u);
	return;
}

// op == 1 when query sum
// op == 2 when query max
// op == 3 when query min 
int query(int u, int l, int r, int op) {
	if ((l > r(u) or r < l(u)) and op == 1) return 0;
	if ((l > r(u) or r < l(u)) and op == 2) return -INF;
	if ((l > r(u) or r < l(u)) and op == 3) return INF;
	if (l <= l(u) and r >= r(u) and op == 1) return sum(u);
	if (l <= l(u) and r >= r(u) and op == 2) return mx(u);
	if (l <= l(u) and r >= r(u) and op == 3) return mn(u);
	PushDown(u);
	if (op == 1) return query(lson(u), l, r, op) + query(rson(u), l, r, op);
	if (op == 2) return max(query(lson(u), l, r, op), query(rson(u), l, r, op));
	if (op == 3) return min(query(lson(u), l, r, op), query(rson(u), l, r, op));
}

void ChangePath(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		ChangePaN(1, dfn[top[u]], dfn[u]);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	ChangePaN(1, dfn[v] + 1, dfn[u]);
}

int QueryPath(int u, int v, int op) {
	int res = 0;
	if (op == 2) res = -INF;
	if (op == 3) res = INF;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		if (op == 1) res += query(1, dfn[top[u]], dfn[u], op);
		if (op == 2) res = max(res, query(1, dfn[top[u]], dfn[u], op));
		if (op == 3) res = min(res, query(1, dfn[top[u]], dfn[u], op));
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	if (op == 1) res += query(1, dfn[v] + 1, dfn[u], op);
	if (op == 2) res = max(res, query(1, dfn[v] + 1, dfn[u], op));
	if (op == 3) res = min(res, query(1, dfn[v] + 1, dfn[u], op));
	return res % mod;
}

int main() {
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	memset(head, -1, sizeof head);
	input(n);
	for (int i = 1; i < n; ++ i) {
		input(u), input(v), input(w);
		u ++, v ++;
		add(u, v, w), add(v, u, w);
		se[i] = {u, v};
	}

	dfs1(1, 1, 1);
	dfs2(1, 1);
	build(1, 1, n);
	
	input(m);
	while (m --) {
		cin >> op;
		input(u), input(v);
		if (op == "C") {
			int tmp;
			if (dep[se[u].u] > dep[se[u].v]) tmp = se[u].u;
			else tmp = se[u].v;
			ChangeVal(1, dfn[tmp], dfn[tmp], v);
		}
		u ++, v ++;
		if (op == "N") ChangePath(u, v);
		if (op == "SUM") output(QueryPath(u, v, 1));
		if (op == "MAX") output(QueryPath(u, v, 2));
		if (op == "MIN") output(QueryPath(u, v, 3));
	}
	return 0;
}
