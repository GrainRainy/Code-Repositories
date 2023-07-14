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
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
const int M = N << 1;

int n, m;
int op, u, v, k;
// basic things
int head[N], idx, w[N];
struct Node {
	int nxt, to;
}edge[M];
// graph
int dfn[N], nw[N], stamp;
int dep[N], siz[N], top[N], fa[N], son[N];
// top refers to the top point of the chain 
// Note: especially refers to the heavy son 
// cutting trees 

struct SegmentTree {
	int l, r;
	LL sum, tag;
	
	#define l(x) tr[x].l
	#define r(x) tr[x].r
	#define sum(x) tr[x].sum
	#define tag(x) tr[x].tag
}tr[N << 2];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void init(int u, int father, int depth) {
	dep[u] = depth, fa[u] = father, siz[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == father) continue;
		init(j, u, depth + 1);
		siz[u] += siz[j];
		if (siz[son[u]] < siz[j]) son[u] = j;
	}
}

void dfs(int u, int t) {
	dfn[u] = ++ stamp, nw[stamp] = w[u], top[u] = t;
	if (!son[u]) return;
	dfs(son[u], t);
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == fa[u] or j == son[u]) continue;
		dfs(j, j);
	}
}

/*** Segment Tree ***/
void PushUp(int u) {
	sum(u) = sum(lson) + sum(rson);
}

void PushDown(int u) {
	if (tag(u)) {
		sum(lson) += tag(u) * (r(lson) - l(lson) + 1);
		tag(lson) += tag(u);
		sum(rson) += tag(u) * (r(rson) - l(rson) + 1);
		tag(rson) += tag(u);
		tag(u) = 0;
	}
}

void build(int u, int l, int r) {
	tr[u] = {l, r, nw[r], 0};
	if (l == r) return;
	int mid = l + r >> 1;
	build(lson, l, mid), build(rson, mid + 1, r);
	PushUp(u);
}

void change(int u, int l, int r, int k) {
	if (l > r(u) or r < l(u)) return;
	if (l <= l(u) and r >= r(u)) {
		sum(u) += (r(u) - l(u) + 1) * k;
		tag(u) += k;
		return;
	}
	PushDown(u);
	change(lson, l, r, k);
	change(rson, l, r, k);
	PushUp(u);
}

LL query(int u, int l, int r) {
	if (l <= l(u) and r >= r(u)) return sum(u);
	PushDown(u);
	int mid = l(u) + r(u) >> 1;
	LL res = 0;
	if (l <= mid) res += query(lson, l, r);
	if (r > mid) res += query(rson, l, r);
	return res;
}

/*** Cutting Heavy Chains ***/

void ChangePath(int u, int v, int k) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		change(1, dfn[top[u]], dfn[u], k);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	change(1, dfn[v], dfn[u], k);
}

LL QueryPath(int u, int v) {
	LL res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		res += query(1, dfn[top[u]], dfn[u]);
		u = fa[top[u]];
	} 
	if (dep[u] < dep[v]) swap(u, v);
	res += query(1, dfn[v], dfn[u]);
	return res;
}

inline void ChangeTree(int u, int k) {
	return change(1, dfn[u], dfn[u] + siz[u] - 1, k), void();
}

inline LL QueryTree(int u) {
	return query(1, dfn[u], dfn[u] + siz[u] - 1);
}

int main() {
	memset(head, -1, sizeof head);
	input(n);
	for (int i = 1; i <= n; i ++) input(w[i]);
	for (int i = 1; i < n; i ++) {
		input(u), input(v);
		add(u, v), add(v, u);
	}
	
	init(1, -1, 1);
	dfs(1, 1);
	build(1, 1, n);
	
	input(m);
	while (m --) {
		input(op);
		if (op == 1) {
			input(u), input(v), input(k);
			ChangePath(u, v, k);
		}
		if (op == 2) {
			input(u), input(k);
			ChangeTree(u, k);
		}
		if (op == 3) {
			input(u), input(v);
			output(QueryPath(u, v));
		}
		if (op == 4) {
			input(u);
			output(QueryTree(u));
		}
	}
	return 0;
}
