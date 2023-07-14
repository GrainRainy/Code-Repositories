#include <iostream>
#include <cstring>
#include <algorithm>

#define __DEBUG__ puts("__DEBUG__");
#define lson (u << 1)
#define rson (u << 1 | 1)

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

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int n, u, v, w, dot;
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
	int l, r, max;
	int cvt, adt;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define mx(x) tree[x].max
	#define cvt(x) tree[x].cvt
	#define adt(x) tree[x].adt
}tree[N << 2];
// Segment Tree 
int siz[N], fa[N], hs[N], dep[N], tmpw[N];
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
		tmpw[j] = edge[i].w;
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	dfn[u] = ++ stamp, top[u] = Top, nw[stamp] = tmpw[u];
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == fa[u] or j == hs[u]) continue;
		dfs2(j, j);
	}
}

void PushUp(int u) {
	mx(u) = max(mx(lson), mx(rson));
}

void PushDown(int u) {
	if (~cvt(u)) {
		cvt(lson) = cvt(rson) = cvt(u);
		mx(lson) = mx(rson) = cvt(u);
		adt(lson) = adt(rson) = 0;
		cvt(u) = -1;
	}
	if (adt(u)) {
		adt(lson) += adt(u), adt(rson) += adt(u);
		mx(lson) += adt(u), mx(rson) += adt(u);
		adt(u) = 0;
	}
	return;
}

void build(int u, int l, int r) {
	tree[u] = {l, r, nw[l], -1, 0};
	if (l == r) return;
	int mid = l + r >> 1;
	build(lson, l, mid), build(rson, mid + 1, r);
	PushUp(u);
}

void Cover(int u, int l, int r, int val){
	if (l > r(u) or r < l(u)) return;
	if (l <= l(u) and r >= r(u)) {
		mx(u) = cvt(u) = val, adt(u) = 0;
		return;
	}
	PushDown(u);
	Cover(lson, l, r, val), Cover(rson, l, r, val);
	PushUp(u);
	return;
}

void Add(int u, int l, int r, int val) {
	if (l > r(u) or r < l(u)) return;
	if (l <= l(u) and r >= r(u)) {
		mx(u) += val, adt(u) += val;
		return;
	}
	PushDown(u);
	Add(lson, l, r, val), Add(rson, l, r, val);
	PushUp(u);
	return;
}

int Query(int u, int l, int r) {
	if (l > r(u) or r < l(u)) return -INF;
	if (l <= l(u) and r >= r(u)) return mx(u);
	PushDown(u);
	return max(Query(lson, l, r), Query(rson, l, r));
}

void CoverPath(int u, int v, int val) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		Cover(1, dfn[top[u]], dfn[u], val);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	Cover(1, dfn[v] + 1, dfn[u], val);
	return;
}

void AddPath(int u, int v, int val) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		Add(1, dfn[top[u]], dfn[u], val);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	Add(1, dfn[v] + 1, dfn[u], val);
	return;
}

int QueryPath(int u, int v) {
	int res = -INF;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		res = max(res, Query(1, dfn[top[u]], dfn[u]));
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	res = max(res, Query(1, dfn[v] + 1, dfn[u]));
	return res;
} 

int main() {
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	memset(head, -1, sizeof head);
	input(n);
	for (int i = 1; i < n; ++ i) {
		input(u), input(v), input(w);
		add(u, v, w), add(v, u, w);
		se[i] = {u, v};
	}
	
	dfs1(1, 1, 1);
	dfs2(1, 1);
	build(1, 1, n);
	
	while (cin >> op, op != "Stop") {
		input(u), input(v);
		if (op == "Change") {
			if (dep[se[u].u] > dep[se[u].v]) dot = se[u].u;
			else dot = se[u].v;
			Cover(1, dfn[dot], dfn[dot], v);
		}
		if (op == "Cover") input(w), CoverPath(u, v, w);
		if (op == "Add") input(w), AddPath(u, v, w);
		if (op == "Max") output(QueryPath(u, v));
	}
	return 0;
}
