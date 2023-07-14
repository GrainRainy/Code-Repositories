#include <iostream>
#include <cstring>
#include <algorithm>

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
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top -- ] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;

const int N = 1e5 + 10;
int n, q, ary[N], a, b, c, d;
struct segmentTree {
	int sum, pre, suf, mx;
	#define sum(x) tree[x].sum
	#define pre(x) tree[x].pre
	#define suf(x) tree[x].suf
	#define mx(x) tree[x].mx
	segmentTree operator + (const segmentTree &t) const {
		segmentTree res;
		res.sum = sum + t.sum;
		res.pre = max(pre, sum + t.pre);
		res.suf = max(t.suf, suf + t.sum);
		res.mx = max({mx, t.mx, suf + t.pre});
		return res;
	}
}tree[N << 2];

void build(int u, int tl, int tr) {
	if (tl == tr) return sum(u) = pre(u) = suf(u) = mx(u) = ary[tl], void();
	int mid = tl + tr >> 1;
	build(lson, tl, mid), build(rson, mid + 1, tr);
	tree[u] = tree[lson] + tree[rson];
	return;
}

segmentTree subQuery(int u, int tl, int tr, int l, int r) {
	if (l > r) return {0, 0, 0, 0};
	if (tl >= l and tr <= r) return tree[u];
	int mid = tl + tr >> 1;
	if (l > mid) return subQuery(rson, mid + 1, tr, l, r);
	if (r <= mid) return subQuery(lson, tl, mid, l, r);
	return subQuery(lson, tl, mid, l, r) + subQuery(rson, mid + 1, tr, l ,r);
}

int query(int a, int b, int c, int d) {
	if (c > b) return subQuery(1, 1, n, a, b).suf + subQuery(1, 1, n, b + 1, c - 1).sum + subQuery(1, 1, n, c, d).pre;
	else {
		int res = subQuery(1, 1, n, c, b).mx;
		if (a < c) res = max(res, subQuery(1, 1, n, a, c).suf + subQuery(1, 1, n, c, d).pre - ary[c]);
		if (b < d) res = max(res, subQuery(1, 1, n, a, b).suf + subQuery(1, 1, n, b, d).pre - ary[b]);
		return res;
	}
}

void solve() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(ary[i]);
	build(1, 1, n);
	input(q);
	while (q --) {
		input(a), input(b), input(c), input(d);
		output(query(a, b, c, d));
	}
	return;
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0; 
}

