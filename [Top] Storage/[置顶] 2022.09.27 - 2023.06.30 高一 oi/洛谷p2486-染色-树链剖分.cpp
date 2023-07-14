#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using LL = long long;

#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
#define mid (l + r >> 1)

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

const int N = 1e6 + 10;
int n, m, u, v, c[N];
char op[3];
int tmpa, tmpb, tmpc;
// basis
int head[N], idx;
struct Node {
	int nxt, to;
}edge[N << 1];
// graph 
struct SegmentTree {
	int l, r;
	int lc, rc, cnt, tag;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define lc(x) tree[x].lc
	#define rc(x) tree[x].rc
	#define cnt(x) tree[x].cnt
	#define tag(x) tree[x].tag
}tree[N << 2];
int dep[N], fa[N], siz[N], hs[N];
int stamp, dfn[N], nc[N], top[N];
// Cutting Heavy Chains (Chinglish)
struct Tmp {
	int lc, rc, cnt;
	Tmp operator ~ () {
		return {rc, lc, cnt};
	}
	Tmp operator + (Tmp t) {
		if (!t.cnt) return *this;
		if (!cnt) return t;
		return (Tmp){lc, t.rc, t.cnt + cnt - (t.lc == rc)};
	}
};
// Query Struct 

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
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
	return;
}

void dfs2(int u, int TmpTop) {
	dfn[u] = ++ stamp, nc[stamp] = c[u], top[u] = TmpTop;
	if (!hs[u]) return;
	dfs2(hs[u], TmpTop);
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == fa[u] or j == hs[u]) continue;
		dfs2(j, j);
	}
	return;
}

inline void PushUp(int u) {
	cnt(u) = cnt(lson(u)) + cnt(rson(u)) - (rc(lson(u)) == lc(rson(u)));
	lc(u) = lc(lson(u)), rc(u) = rc(rson(u));
}

inline void PushDown(int u) {
	if (!tag(u)) return;
	cnt(lson(u)) = cnt(rson(u)) = 1;
	lc(lson(u)) = rc(lson(u)) = lc(rson(u)) = rc(rson(u)) = tag(u);
	tag(lson(u)) = tag(rson(u)) = tag(u);
	tag(u) = 0;
	return;
}

void build(int u, int l, int r) {
	tree[u] = {l, r, nc[l], nc[l], 1, 0};
	if (l == r) return;
	build(lson(u), l, mid), build(rson(u), mid + 1, r);
	PushUp(u);
}

void change(int u, int l, int r, int k) {
	if (l(u) > r or r(u) < l) return;
	if (l(u) >= l and r(u) <= r) {
		cnt(u) = 1, tag(u) = k;
		lc(u) = rc(u) = k;
		return;
	}
	PushDown(u);
	change(lson(u), l, r, k), change(rson(u), l, r, k);
	PushUp(u);
	return;
}

Tmp query(int u, int l, int r) {
	if (l(u) > r or r(u) < l) return {0, 0, 0};
	if (l(u) >= l and r(u) <= r) return {lc(u), rc(u), cnt(u)};
	PushDown(u);
	return query(lson(u), l, r) + query(rson(u), l, r);	
}

void ChangePath(int u, int v, int k) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		change(1, dfn[top[u]], dfn[u], k);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	change(1, dfn[v], dfn[u], k);
	return;
}

Tmp QueryPath(int u, int v) {
	Tmp AnsLeft = {0, 0, 0}, AnsRight = {0, 0, 0}, Mid = {0, 0, 0};
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) {
			AnsRight = query(1, dfn[top[v]], dfn[v]) + AnsRight; 
			v = fa[top[v]];
		}
		else {
			AnsLeft = AnsLeft + (~query(1, dfn[top[u]], dfn[u]));
			u = fa[top[u]];
		}
	}
	if (dep[u] < dep[v]) Mid = query(1, dfn[u], dfn[v]);
	else Mid = ~query(1, dfn[v], dfn[u]);
	return AnsLeft + Mid + AnsRight;
}

int main() {
//	freopen("test1.in", "r", stdin);
	memset(head, -1, sizeof head);
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) input(c[i]);
	for (int i = 1; i < n; ++ i) {
		input(u), input(v);
		add(u, v);
		add(v, u);
	}
	
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, 1, n);
	
	while (m --) {
		cin >> op;
		if (op[0] == 'C') {
			input(tmpa), input(tmpb), input(tmpc);
			ChangePath(tmpa, tmpb, tmpc);
		}
		if (op[0] == 'Q') {
			input(tmpa), input(tmpb);
			output(QueryPath(tmpa, tmpb).cnt);
		}
	}
	return 0;
}
