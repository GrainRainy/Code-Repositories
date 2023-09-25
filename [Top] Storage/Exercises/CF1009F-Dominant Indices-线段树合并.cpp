#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, ans[N], head[N], idx, ttp;
struct Node { int nxt, to; }edge[N << 1];
int dep[N], fa[N];
struct SegmentTree { int l, r, mx, mxc; }tree[N * 22];
#define l(x) tree[x].l
#define r(x) tree[x].r
#define mx(x) tree[x].mx
#define mxc(x) tree[x].mxc

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0'); 
}

template <typename T> inline void ot(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

void dfs1(int u, int depth, int father) {
	dep[u] = depth, fa[u] = father; 
	for (int i = head[u], j; ~i; i = edge[i].nxt)
		if ((j = edge[i].to) != father) dfs1(j, depth + 1, u);
}

inline void pushup(int u) {
	if (!r(u) or mxc(l(u)) >= mxc(r(u))) mx(u) = mx(l(u)), mxc(u) = mxc(l(u));
	else if (!l(u) or mxc(l(u)) < mxc(r(u))) mx(u) = mx(r(u)), mxc(u) = mxc(r(u));
}

int insert(int tl, int tr, int pos) {
	int u = ++ ttp; mxc(u) ++;
	if (tl == tr) return mx(u) = tl, u;
	int mid = tl + tr >> 1;
	if (pos <= mid) l(u) = insert(tl, mid, pos);
	else r(u) = insert(mid + 1, tr, pos);
	return pushup(u), u;
}

int merge(int x, int y, int tl, int tr) {
	if (!x or !y) return x | y;
	if (tl == tr) return mxc(x) += mxc(y), x;
	int mid = tl + tr >> 1;
	l(x) = merge(l(x), l(y), tl, mid), r(x) = merge(r(x), r(y), mid + 1, tr);
	return pushup(x), x;
}

int dfs2(int u) {
	int tru = insert(1, n, dep[u]);
	for (int i = head[u], j; ~i; i = edge[i].nxt)
		if ((j = edge[i].to) != fa[u]) merge(tru, dfs2(j), 1, n);
	ans[u] = mx(tru) - dep[u];
	return tru;
}

int main() {
	rd(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) rd(a), rd(b), add(a, b), add(b, a);
	dfs1(1, 1, 1), dfs2(1);
	for (int i = 1; i <= n; ++ i) ot(ans[i]);
	return 0;
}
