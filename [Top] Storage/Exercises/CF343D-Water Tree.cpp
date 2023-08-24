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

const int N = 5e5 + 10;
int n, m, u, v, op, tmp;
// basic things
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
int dep[N], fa[N], siz[N], hs[N];
int stamp, dfn[N], top[N];

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
	return;
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
	return;
}

inline void PushUp(int u) {
	sum(u) = sum(lson) + sum(rson);
}

inline void PushDown(int u) {
	if (tag(u) == -1) return;
	sum(lson) = (r(lson) - l(lson) + 1) * tag(u);
	sum(rson) = (r(rson) - l(rson) + 1) * tag(u);
	tag(lson) = tag(rson) = tag(u);
	tag(u) = -1;
	return;
}

void build(int u, int l, int r) {
	tree[u] = {l, r, 0, -1};
	if (l == r) return;
	int mid = l + r >> 1;
	build(lson, l, mid), build(rson, mid + 1, r);
	return;
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

int query(int u, int x) {
	if (!sum(u)) return 0;
	if (sum(u) == r(u) - l(u) + 1) return 1;
	int mid = l(u) + r(u) >> 1;
	if (x <= mid) return query(lson, x);
	return query(rson, x);
}

void ChangeTree(int u, int k) {
	return change(1, dfn[u], dfn[u] + siz[u] - 1, k), void();
}

void ChangePath(int u, int k) {
	while (top[u] != 1) {
		change(1, dfn[top[u]], dfn[u], k);
		u = fa[top[u]];
	}
	change(1, 1, dfn[u], k);
	return;
}

int main() {
	memset(head, -1, sizeof head);
	
	input(n);
	for (int i = 1; i < n; i ++) {
		input(u), input(v);
		add(u, v), add(v, u);
	}
	
	dfs1(1, 1, 1);
	dfs2(1, 1);
	build(1, 1, n);
	
	input(m);
	while (m --) {
		input(op), input(tmp);
		if (op == 1) ChangeTree(tmp, 1);
		if (op == 2) ChangePath(tmp, 0);
		if (op == 3) {
			int type = query(1, dfn[tmp]);
			if (type) puts("1");
			else puts("0");
		}
	}
//	puts("__DEBUG__");
//	for (int i =1 ; i <= n; i ++) {
//		cout << i << " " << dfn[i] << endl;
//	}
	return 0;
}
