#include <bits/stdc++.h>
#define fi first
#define se second 
#define lson (u << 1)
#define rson (u << 1 | 1)
#define __DEBUG__ puts("__DEBUG__");
#define DEBUG(x) cout << #x << ' ' << x << '\n';
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
int n, q, k;
int head[N], idx;
struct Node { int nxt, to, w; }edge[N << 1];
// bases 
int siz[N], dep[N], fa[N], hs[N], w[N];
int dfn[N], top[N], stamp, nw[N], mnw[N];
// decomposition 
int dis[N]; bool st[N];
priority_queue<PII, vector<PII>, greater<PII>> heap;
// shortest path 
struct SegmentTree { int sum, mn; }tree[N << 2];

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void dijkstra() {
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1, tmp; i <= k; ++ i)
		input(tmp), heap.push({dis[tmp] = 0, tmp});
	while (heap.size()) {
		int u = heap.top().se; heap.pop();
		if (st[u]) continue;
		st[u] = true;
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (dis[j] > dis[u] + edge[i].w) {
				dis[j] = dis[u] + edge[i].w;
				if (!st[j]) heap.push({dis[j], j});
			}
		}
	}
}

void dfs1(int u, int depth, int father) {
	dep[u] = depth, fa[u] = father, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs1(j, depth + 1, u);
		w[j] = edge[i].w;
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	dfn[u] = ++ stamp, nw[stamp] = w[u], mnw[stamp] = dis[u], top[u] = Top;
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

inline void pushUp(int u) {
	tree[u].sum = tree[lson].sum + tree[rson].sum;
	tree[u].mn = min(tree[lson].mn, tree[rson].mn);
}

inline void update(int &mn, int &sum, SegmentTree t) {
	mn = min(mn, t.mn), sum += t.sum;
}

void build(int u, int tl, int tr) {
	if (tl == tr) return tree[u] = {nw[tl], mnw[tl]}, void();
	int mid = tl + tr >> 1;
	build(lson, tl, mid), build(rson, mid + 1, tr);
	pushUp(u);
}

SegmentTree query(int u, int tl, int tr, int l, int r) {
	if (tl >= l and tr <= r) return tree[u];
	int mid = tl + tr >> 1, mn = 0x3f3f3f3f, res = 0;
	if (l <= mid) update(mn, res, query(lson, tl, mid, l, r));
	if (r > mid) update(mn, res, query(rson, mid + 1, tr, l, r));
	return {res, mn};
}

int queryPath(int u, int v) {
	int mn = 0x3f3f3f3f, res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		update(mn, res, query(1, 1, n, dfn[top[u]], dfn[u]));
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	update(mn, res, query(1, 1, n, dfn[v] + 1, dfn[u]));
	mn = min(mn, mnw[dfn[v]]);
	return res + mn * 2;
}

int main() {
	memset(head, -1, sizeof head);
	input(n), input(q), input(k);
	for (int i = 1, u, v, w; i < n; ++ i) {
		input(u), input(v), input(w);
		add(u, v, w), add(v, u, w);
	}
	dijkstra();
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, 1, n);
	for (int i = 1, u, v; i <= q; ++ i) 
		input(u), input(v), output(queryPath(u, v));
	return 0;
}
