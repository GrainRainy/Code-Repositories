#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 10 + 3;
const int M = 1e5 + 10;
const LL INF = 1e15;
LL n, m, q, ttp, gh[N][M];
struct SegmentTree {
	int rgl, rgr;
	struct Node {
		LL sm, pre, suf, mx;
		#define l(u) ((u) << 1)
		#define r(u) ((u) << 1 | 1)
		#define sm(x) tree[x].sm
		#define pre(x) tree[x].pre
		#define suf(x) tree[x].suf
		#define mx(x) tree[x].mx
		Node operator + (const Node &t) const {
			Node res;
			res.sm = sm + t.sm;
			res.pre = max(pre, sm + t.pre);
			res.suf = max(t.suf, t.sm + suf);
			res.mx = max({mx, t.mx, suf + t.pre});
			return res;
		}
	}tree[M << 2];
	void build(int u, int tl, int tr) {
		if (tl == tr) {
			LL res = 0;
			for (int i = rgl; i <= rgr; i ++)
				res += gh[i][tl];
			sm(u) = pre(u) = suf(u) = mx(u) = res;
			return;
		}
		int mid = tl + tr >> 1;
		build(l(u), tl, mid), build(r(u), mid + 1, tr);
		tree[u] = tree[l(u)] + tree[r(u)];
	}
	void modify(int u, int tl, int tr, int p, int v) {
//		cerr << "modify " << ' ' << p << ' ' << v << '\n';
		if (tl == tr) {
			sm(u) += v, pre(u) += v, suf(u) += v, mx(u) += v;
			return;
		}
		int mid = tl + tr >> 1;
		if (p <= mid) modify(l(u), tl, mid, p, v);
		else modify(r(u), mid + 1, tr, p, v);
		tree[u] = tree[l(u)] + tree[r(u)];
	}
	Node query(int u, int tl, int tr, int l, int r) {
		if (tl > r or tr < l) return {0, -INF, -INF, -INF};
		if (l <= tl and tr <= r) return tree[u];
		int mid = tl + tr >> 1;
		return query(l(u), tl, mid, l, r) + query(r(u), mid + 1, tr, l, r);
	}
}sg[60];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void ot(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int main() {
//	freopen("c.in", "r", stdin);
//	freopen("c.out", "w", stdout);
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			rd(gh[i][j]);
	for (int i = 1; i <= n; ++ i)
		for (int j = i; j <= n; ++ j) {
			++ ttp, sg[ttp].rgl = i, sg[ttp].rgr = j;
			sg[ttp].build(1, 1, m);
		}
	rd(q);
	for (int i = 1, op, x, y, a, b, v; i <= q; ++ i) {
		rd(op), rd(x), rd(y);
		if (op == 1) {
			rd(v);
			for (int j = 1; j <= ttp; ++ j)
				if (sg[j].rgl <= x and x <= sg[j].rgr)
					sg[j].modify(1, 1, m, y, v - gh[x][y]);
			gh[x][y] = v;
		} else {
			rd(a), rd(b);
			LL mx = -INF;
			for (int j = 1; j <= ttp; ++ j)
				if (x <= sg[j].rgl and sg[j].rgr <= a)
					mx = max(mx, sg[j].query(1, 1, m, y, b).mx);
			ot(mx);
		}
	}
	return 0;
}
