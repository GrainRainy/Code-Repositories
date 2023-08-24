#include <iostream>
#include <cstring>
#include <algorithm>
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
	do st[ ++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top -- ] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
const int M = 1e5;
const int O = N << 6;
int n, m, x, y, z;
int ans[N];
// basis 
int head[N], idx;
struct Node {
	int nxt, to;
}edge[N << 1];
// graph 
int siz[N], dep[N], hs[N], top[N], fa[N];
// lca 
int rt[N], tTop, lson[O], rson[O];
int cnt[O], mx[O];
// Segment Tree 

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int father) {
	dep[u] = dep[father] + 1, fa[u] = father, siz[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == father) continue;
		dfs1(j, u);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	top[u] = Top;
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
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

void update(int u) {
	if (cnt[lson[u]] < cnt[rson[u]]) {
		mx[u] = mx[rson[u]];
		cnt[u] = cnt[rson[u]];
	} 
	else {
		mx[u] = mx[lson[u]];
		cnt[u] = cnt[lson[u]];
	}
	return;
}

int merge(int a, int b, int l, int r) {
	if (!a or !b) return a | b;
	if (l == r) {
		cnt[a] += cnt[b];
		return a;
	}
	int mid = l + r >> 1;
	lson[a] = merge(lson[a], lson[b], l, mid);
	rson[a] = merge(rson[a], rson[b], mid + 1, r);
	update(a);
	return a;
}

int modify(int &u, int tl, int tr, int pos, int val) {
	if (!u) u = ++ tTop;
	if (tl == tr) {
		cnt[u] += val;
		mx[u] = pos;
		return u;
	}
	int mid = tl + tr >> 1;
	if (pos <= mid) modify(lson[u], tl, mid, pos, val);
	if (pos > mid) modify(rson[u], mid + 1, tr, pos, val);
	update(u);
	return u;
}

void calc(int u) {
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == fa[u]) continue;
		calc(j);
		rt[u] = merge(rt[u], rt[j], 1, M);
	}
	if (cnt[rt[u]]) ans[u] = mx[rt[u]];
}

int main() {
	memset(head, -1, sizeof head);
	input(n), input(m);
	for (int i = 1; i < n; ++ i) {
		input(x), input(y);
		add(x, y), add(y, x);
	}

	dfs1(1, 0); dfs2(1, 1);

	while (m --) {
		input(x), input(y), input(z);
		int l = lca(x, y);
		modify(rt[x], 1, M, z, 1);
		modify(rt[y], 1, M, z, 1);
		modify(rt[l], 1, M, z, -1);
		modify(rt[fa[l]], 1, M, z, -1);
	}
	calc(1);
	for (int i = 1; i <= n; ++ i) output(ans[i]);
	return 0;
}
