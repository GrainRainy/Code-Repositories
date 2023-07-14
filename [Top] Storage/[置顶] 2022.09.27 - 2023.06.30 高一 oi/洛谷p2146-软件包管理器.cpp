#include <iostream>
#include <cstring>
#include <algorithm>

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
int n, q, tmp; string op;
// basic things
int head[N], idx;
struct Node {
	int nxt, to;
}edge[N << 1];
// graph 
int stamp, dfn[N];
int dep[N], siz[N], hs[N], top[N], fa[N];
struct SegmentTree{
	int l, r;
	int sum, tag;
	
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define tag(x) tree[x].tag
}tree[N << 2];
// Segment Tree 

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int father, int depth) {
	dep[u] = depth, fa[u] = father, siz[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == father) continue;
		dfs1(j, u, depth + 1);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int SaveTop) {
	dfn[u] = ++ stamp, top[u] = SaveTop;
	if (!hs[u]) return;
	dfs2(hs[u], SaveTop);
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == fa[u] or j == hs[u]) continue;
		dfs2(j, j);
	}
}

inline void PushUp(int u) {
	sum(u) = sum(lson) + sum(rson);
}

inline void PushDown(int u) {
	if (tag(u) == -1) return;
	sum(lson) = (r(lson) - l(lson) + 1) * tag(u);
	tag(lson) = tag(u);
	sum(rson) = (r(rson) - l(rson) + 1) * tag(u);
	tag(rson) = tag(u);
	tag(u) = -1;
	return;
}

void build(int u, int l, int r) {
	tree[u] = {l, r, 0, -1};
	if (l == r) return;
	int mid = l + r >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
}

void change(int u, int l, int r, int k) {
	if (l(u) > r or r(u) < l) return;
	if (l(u) >= l and r(u) <= r) {
		sum(u) = (r(u) - l(u) + 1) * k;
		tag(u) = k;
		return;
	}
	PushDown(u);
	change(lson, l, r, k);
	change(rson, l, r, k);
	PushUp(u);
}

void ChangePath (int u, int v, int k) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		change(1, dfn[top[u]], dfn[u], k);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	change(1, dfn[v], dfn[u], k);
	return;
}

void ChangeTree(int u, int k) {
	return change(1, dfn[u], dfn[u] + siz[u] - 1, k), void();
}

int main() {
	memset(head, -1, sizeof head);
	input(n);
	for (int i = 2; i <= n; i ++) {
		input(tmp); tmp ++;
		add(i, tmp), add(tmp, i);
	}
	
	dfs1(1, 1, 1);
	dfs2(1, 1);
	build(1, 1, n);
	
	input(q);
	while (q --) {
		cin >> op; input(tmp); tmp ++;
		int ori = sum(1);
		if (op[0] == 'i') {
			ChangePath(1, tmp, 1);
			output(sum(1) - ori);
		}
		else {
			ChangeTree(tmp, 0);
			output(ori - sum(1));
		}
	}
	return 0;
}
