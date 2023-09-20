#include <bits/stdc++.h>
#define fi first
#define se second
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e6 + 10;
int n, q, head[N], idx, ans[N], ttp;
struct Node { int nxt, to; }edge[N];
int siz[N], dep[N], fa[N], hs[N], top[N], node[N], dfn[N], stamp;
vector<pair<int, int>> qt[N];

struct SegmentTree { 
	int l, r, cnt;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define cnt(x) tree[x].cnt
}tree[N * 22];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int depth) {
	dep[u] = depth, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		dfs1(j, depth + 1);
		siz[u] += siz[j];
		if (siz[hs[u]] < siz[j]) hs[u] = j;
	}
}

void dfs2(int u, int t) {
	dfn[u] = ++ stamp, node[dfn[u]] = u, top[u] = t;
	if (!hs[u]) return;
	dfs2(hs[u], t);
	for (int i = head[u], j; ~i; i = edge[i].nxt) 
		if (!top[j = edge[i].to]) dfs2(j, j);
}

int kfa(int u, int k) {
	while (dep[u] - dep[top[u]] + 1 <= k)
		k -= dep[u] - dep[top[u]] + 1, u = fa[top[u]];
	return node[dfn[u] - k];
}

int insert(int tl, int tr, int pos) {
	int u = ++ ttp; cnt(u) ++;
	if (tl == tr) return u;
	int mid = tl + tr >> 1;
	if (pos <= mid) return l(u) = insert(tl, mid, pos), u;
	else return r(u) = insert(mid + 1, tr, pos), u;
}

int merge(int x, int y, int tl, int tr) {
	if (!x or !y) return x | y;
	if (tl == tr) return cnt(x) += cnt(y), x;
	int mid = tl + tr >> 1;
	l(x) = merge(l(x), l(y), tl, mid), r(x) = merge(r(x), r(y), mid + 1, tr);
	cnt(x) += cnt(y);
	return x; 
}

int query(int u, int tl, int tr, int pos) {
	if (tl == tr) return cnt(u);
	int mid = tl + tr >> 1;
	if (pos <= mid and !l(u) or pos > mid and !r(u)) return 0;
	if (pos <= mid) return query(l(u), tl, mid, pos);
	else return query(r(u), mid + 1, tr, pos);
}

int dfs(int u) {
	int tru = insert(1, n, dep[u]);
	for (int i = head[u]; ~i; i = edge[i].nxt) merge(tru, dfs(edge[i].to), 1, n);
	if (qt[u].size()) for (auto t : qt[u]) ans[t.fi] = query(tru, 1, n, dep[u] + t.se);
	return tru;
}

int main() {
	rd(n), rd(q);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 2; i <= n; ++ i) rd(fa[i]), add(fa[i], i);
	dfs1(1, 1), dfs2(1, 1);
	for (int i = 1, u, k; i <= q; ++ i) rd(u), rd(k), qt[kfa(u, min(k, dep[u]))].push_back({i, k});
	dfs(1);
	for (int i = 1; i <= q; ++ i) ot(max(ans[i] - 1, 0), " \n"[i == q]);
	
	return 0;
}
