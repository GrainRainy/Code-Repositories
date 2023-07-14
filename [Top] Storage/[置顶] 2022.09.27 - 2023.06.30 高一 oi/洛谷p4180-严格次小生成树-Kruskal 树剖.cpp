#include <bits/stdc++.h>
#define fi first
#define se second
#define lson (u << 1)
#define rson (u << 1 | 1)

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace IO;
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int N = 1e5 + 10;
const int M = 3e5 + 10;
int n, m;
int head[N], idx;
struct Node { int nxt, to, w; } edge[M << 1];
// bases 
LL mstw, smstw = 0x3f3f3f3f3f3f3f3f; 
int mstfa[N];
bool st[M];
struct KruskalEdge { 
	int a, b, w; 
	bool operator < (const KruskalEdge &t) const {return w < t.w; }
}save[M];
// Kruskal 
int dep[N], siz[N], fa[N], hs[N], w[N], nw[N];
int dfn[N], stamp, top[N];
// decomposition
PII tree[N << 2]; // max and submax value 

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

int find(int x) { return mstfa[x] == x ? x : mstfa[x] = find(mstfa[x]); }

void kruskal() {
	sort(save + 1, save + m + 1);
	for (int i = 1; i <= n; ++ i) mstfa[i] = i;
	for (int i = 1, a, b; i <= m; ++ i) {
		a = save[i].a, b = save[i].b;
		if (find(a) != find(b)) {
			mstfa[find(a)] = find(b);
			mstw += save[i].w;
			st[i] = true;
			add(a, b, save[i].w), add(b, a, save[i].w);
		}
	}
	return;
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
	dfn[u] = ++ stamp, top[u] = Top, nw[stamp] = w[u];
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

void pushUp(int u) {
	int tmp[4] = {tree[lson].fi, tree[lson].se, tree[rson].fi, tree[rson].se};
	sort(tmp, tmp + 4, greater<int>());
	for (int i = 1; i < 4; ++ i) 
		if (tmp[i] != tmp[0]) 
			return tree[u] = {tmp[0], tmp[i]}, void();
	return tree[u] = {tmp[0], 0}, void();
}

void build(int u, int tl, int tr) {
	tree[u] = {nw[tl], 0};
	if (tl == tr) return;
	int mid = tl + tr >> 1;
	build(lson, tl, mid), build(rson, mid + 1, tr);
	pushUp(u);
}

int query(int u, int tl, int tr, int l, int r, int val) {
	if (tl >= l and tr <= r) return tree[u].fi == val ? tree[u].se : tree[u].fi;
	int mid = tl + tr >> 1, res = -1;
	if (l <= mid) res = max(res, query(lson, tl, mid, l, r, val));
	if (r > mid) res = max(res, query(rson, mid + 1, tr, l, r, val));
	return res;
}

inline void updateVal(int &max, int &submax, int val) {
	if (val > max) { submax = max, max = val; }
	else if (val > submax) { submax = val; }
	return;
}

int queryPath(int u, int v, int val) {
	int max = -1, submax = -1;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		updateVal(max, submax, query(1, 1, n, dfn[top[u]], dfn[u], val));
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	updateVal(max, submax, query(1, 1, n, dfn[v] + 1, dfn[u], val));
	return max;
}

int main() {
	memset(head, -1, sizeof head);
	input(n), input(m);
	for (int i = 1, x, y, z; i <= m; ++ i) {
		input(x), input(y), input(z);
		save[i] = {x, y, z};
	}
	kruskal();
	dfs1(1, 1, 0), dfs2(1, 1);
	build(1, 1, n);
	for (int i = 1; i <= m; ++ i) 
		if (!st[i] and save[i].a != save[i].b) 
//			cout << save[i].a << ' ' << save[i].b << ' ' << save[i].w << endl;
//			cout << queryPath(save[i].a, save[i].b, save[i].w) << endl;
			smstw = min(smstw, mstw + save[i].w - queryPath(save[i].a, save[i].b, save[i].w));
	cout << smstw << endl;
	return 0;
} 
