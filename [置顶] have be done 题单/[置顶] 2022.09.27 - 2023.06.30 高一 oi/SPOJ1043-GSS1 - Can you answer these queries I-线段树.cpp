#include <iostream>
#include <cstring>
#include <algorithm>

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

#define lson (u << 1)
#define rson (u << 1 | 1)

const int N = 5e4 + 10;
int n, m, l, r;
int ary[N];
struct SegmentTree {
	int sum, mx, pre, suf;
	#define sum(x) tree[x].sum
	#define mx(x) tree[x].mx
	#define pre(x) tree[x].pre
	#define suf(x) tree[x].suf
	void init(int x) { sum = mx = pre = suf = x; }
	SegmentTree operator + (const SegmentTree &t) const {
		SegmentTree res;
		res.sum = sum + t.sum;
		res.mx = max({mx, t.mx, suf + t.pre});
		res.pre = max(pre, sum + t.pre);
		res.suf = max(t.suf, suf + t.sum);
		return res;
	}
}tree[N << 2];

void build(int u, int tl, int tr) {
	if (tl == tr) return tree[u].init(ary[tl]), void();
	int mid = tl + tr >> 1;
	build(lson, tl, mid), build(rson, mid + 1, tr);
	tree[u] = tree[lson] + tree[rson];
}

SegmentTree query(int u, int tl, int tr, int l, int r) {
	if (tl >= l and tr <= r) return tree[u];
	int mid = tl + tr >> 1, res = 0xcfcfcfcf;
	if (l > mid) return query(rson, mid + 1, tr, l, r);
	if (r <= mid) return query(lson, tl, mid, l, r);
	else return (query(lson, tl, mid, l, r) + query(rson, mid + 1, tr, l, r));
}

void print(int u, int tl, int tr) {
	cout << u << ' ' << tl << ' ' << tr << ' ' << sum(u) << ' ' << mx(u) << ' ' << pre(u) << ' ' << suf(u) << endl;
	if (tl == tr) return;
	int mid = tl + tr >> 1;
	print(lson, tl, mid), print(rson, mid + 1, tr);
}

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(ary[i]);
	build(1, 1, n);
	input(m);
	while (m --) {
		input(l), input(r);
		output(query(1, 1, n, l, r).mx);
	}
//	print(1, 1, n);
	return 0;
}
