#include <bits/stdc++.h>
#define lson (u << 1)
#define rson (u << 1 | 1)
#define __DEBUG__ puts("__DEBUG__");
#define debug(x) cout << #x << ' ' << x << endl;
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
using LL = long long;

const int N = 5e4 + 10;
const int MOD = 201314;
int n, m, ans[N];
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
struct Query {
	int id, r, z;
	bool type;
	bool operator < (const Query &t) const {
		return r < t.r;
	}
}q[N];
int fa[N], siz[N], dep[N], hs[N];
int dfn[N], stamp, top[N];
struct SegmentTree {
	int sum, tag;
	#define sum(u) tree[u].sum
	#define tag(u) tree[u].tag
}tree[N << 2];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int father, int depth) {
	dep[u] = depth, fa[u] = father, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
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
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

void pushUp(int u) {
	sum(u) = sum(lson) + sum(rson);
}

void pushDown(int u, int tl, int tr) {
	if (!tag(u)) return;
	int mid = tl + tr >> 1;
	sum(lson) += (mid - tl + 1) * tag(u);
	sum(rson) += (tr - mid) * tag(u);
	tag(lson) += tag(u), tag(rson) += tag(u);
	tag(u) = 0;
}

void modify(int u, int tl, int tr, int l, int r, int val) {
	if (tl >= l and tr <= r) { 
		sum(u) += (tr - tl + 1) * val; 
		tag(u) += val;
		return;
	}
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	if (l <= mid) modify(lson, tl, mid, l, r, val);
	if (r > mid) modify(rson, mid + 1, tr, l, r, val);
	pushUp(u);
}

int query(int u, int tl, int tr, int l, int r) {
	if (tl >= l and tr <= r) return sum(u);
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1, res = 0;
	if (l <= mid) res = (res + query(lson, tl, mid, l, r)) % MOD;
	if (r > mid) res = (res + query(rson, mid + 1, tr, l, r)) % MOD;
	return res;
}

void modifyPath(int u) {
	while (top[u] ^ 1) {
		modify(1, 1, n, dfn[top[u]], dfn[u], 1);
		u = fa[top[u]];
	}
	modify(1, 1, n, 1, dfn[u], 1);
}

int queryPath(int u) {
	int res = 0;
	while (top[u] ^ 1) {
		res = ((LL)res + query(1, 1, n, dfn[top[u]], dfn[u]));
		u = fa[top[u]];
	}
	res = (res + query(1, 1, n, 1, dfn[u]));
	return res;
}

int main() {
	input(n), input(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 2, f; i <= n; ++ i) {
		input(f); f ++;
		add(i, f), add(f, i);
	}
	dfs1(1, 0, 1);
	dfs2(1, 1);
	for (int i = 1, l, r, z; i <= m; ++ i) {
		input(l), input(r), input(z);
		l ++, r ++, z ++;
		q[(i << 1) - 1] = {i, l - 1, z, 1};
		q[i << 1] = {i, r, z, 0};
	}
	sort(q + 1, q + (m << 1) + 1);
	int pos = 0;
	for (int i = 1; i <= (m << 1); ++ i) {
		while (pos < q[i].r) modifyPath(++ pos);
		if (q[i].type) ans[q[i].id] -= queryPath(q[i].z);
		else ans[q[i].id] += queryPath(q[i].z);
	}
	for (int i = 1; i <= m; ++ i) output((ans[i] % MOD + MOD) % MOD);
	return 0;
}
