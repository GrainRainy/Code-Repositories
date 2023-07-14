#include <iostream>
#include <cstring>

namespace IO {
	template <typename T> inline void input(T &x) {
		x= 0; char c = getchar();
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

using namespace std;
using namespace IO;
using LL = long long;

const int N = 1e5 + 10;
const int NLOGN = 2e6 + 10;

int n, col[N];
LL ans[N];
// basis 
int head[N], idx;
struct Node {
	int nxt, to;
}edge[N << 1];
int rt[N], cnt;
struct SegmentTree {
	int lson, rson, cnt; LL mx;
	
	#define lson(x) tree[x].lson
	#define rson(x) tree[x].rson
	#define mx(x) tree[x].mx
	#define cnt(x) tree[x].cnt
}tree[NLOGN << 1];
// Segment Tree 

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void pushUp(int u) {
	if (cnt(lson(u)) > cnt(rson(u))) 
		mx(u) = mx(lson(u)), cnt(u) = cnt(lson(u));
	if (cnt(lson(u)) < cnt(rson(u)))
		mx(u) = mx(rson(u)), cnt(u) = cnt(rson(u));
	if (cnt(lson(u)) == cnt(rson(u)))
		mx(u) = mx(lson(u)) + mx(rson(u)), cnt(u) = cnt(lson(u));
}

void modify(int &u, int tl, int tr, int pos, int val) {
	if (!u) u = ++ cnt;
	if (tl == tr) { mx(u) = pos, cnt(u) += val; return;	}
	int mid = tl + tr >> 1;
	if (pos <= mid) modify(lson(u), tl, mid, pos, val);
	else modify(rson(u), mid + 1, tr, pos, val);
	pushUp(u);
	return;
}

int merge(int a, int b, int tl, int tr) {
	if (!a or !b) return a | b;
	if (tl == tr) { mx(a) = tl, cnt(a) += cnt(b); return a; }
	int mid = tl + tr >> 1;
	lson(a) = merge(lson(a), lson(b), tl, mid);
	rson(a) = merge(rson(a), rson(b), mid + 1, tr);
	pushUp(a);
	return a;
}

void dfs(int u, int fa) {
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		dfs(j, u);
		merge(rt[u], rt[j], 1, N);
	}
	modify(rt[u], 1, N, col[u], 1);
	ans[u] = mx(rt[u]);
	return;
}

signed main() {
	input(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= n; ++ i) 
		input(col[i]), rt[i] = ++ cnt;
	
	for (int i = 1, u, v; i < n; ++ i) {
		input(u), input(v);
		add(u, v), add(v, u);
	}
	
	dfs(1, 0);
	
	for (int i = 1; i <= n; ++ i) output(ans[i], ' ');
	return puts(""), 0;
}
