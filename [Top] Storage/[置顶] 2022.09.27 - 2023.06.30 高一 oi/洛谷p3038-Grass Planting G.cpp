#include <iostream>
#include <cstring>
#include <algorithm>

#define __DEBUG__ puts("YES");
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
char op[3];
int n, m, u, v;

int head[N], idx;
struct Node {
	int nxt, to;
}edge[N << 1];
// graph
struct SegmentTree {
	int l, r;
	int sum, tag;

	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define tag(x) tree[x].tag
}tree[N << 2];
// SegmentTree
int siz[N], fa[N], dep[N], hs[N];
int stamp, dfn[N], top[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int father, int depth) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
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
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == fa[u] or j == hs[u]) continue;
		dfs2(j, j);
	}
}

void PushDown(int u) {
	if (!tag(u)) return;
	sum(lson) += (r(lson) - r(lson) + 1) * tag(u);
	sum(rson) += (r(rson) - r(rson) + 1) * tag(u);
	tag(lson) += tag(u), tag(rson) += tag(u);
	tag(u) = 0;
}

void PushUp(int u) {
	sum(u) = sum(lson) + sum(rson);
}

void build(int u, int l, int r) {
	tree[u] = {l, r, 0, 0};
	if (l == r) return;
	int mid = l + r >> 1;
	build(lson, l, mid), build(rson, mid + 1, r);
	PushUp(u);
}

void change(int u, int l, int r) {
	if (l > r(u) or r < l(u)) return;
	if (l <= l(u) and r >= r(u)) {
		tag(u) ++;
		sum(u) += r(u) - l(u) + 1;
		return;
	}
	PushDown(u);
	change(lson, l, r), change(rson, l, r);
	PushUp(u);
}

int query(int u, int l, int r) {
	if (l > r(u) or  r < l(u)) return 0;
	if (l <= l(u) and r >= r(u)) return sum(u);
	PushDown(u);
	return query(lson, l, r) + query(rson, l, r);
}

void ChangePath(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		change(1, dfn[top[u]], dfn[u]);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	change(1, dfn[v] + 1, dfn[u]);
	return;
}

int QueryPath(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	return query(1, dfn[u], dfn[u]);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	memset(head, -1, sizeof head);
	
	input(n), input(m);
	for (int i = 1; i < n; ++ i) {
		input(u), input(v);
		add(u, v), add(v, u);
	}
	
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, 1, n); 

	while (m --) {
		cin >> op; input(u), input(v);
		if (op[0] == 'P') ChangePath(u, v);
		if (op[0] == 'Q') output(QueryPath(u, v));
	}
	return 0;
}
