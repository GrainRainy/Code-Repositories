#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
namespace IO {
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
}

using namespace IO;
using namespace std;
const int N = 1e5 + 10;
int n, m;
bool ary[N];
struct SegmentTree {
	int len, cnt, ctag, lc[2], rc[2], mx[2];
	bool rtag;
	#define l(x) ((x) << 1)
	#define r(x) ((x) << 1 | 1)
	#define len(x) tree[x].len
	#define cnt(x) tree[x].cnt
	#define ctag(x) tree[x].ctag
	#define rtag(x) tree[x].rtag
	#define lc(x) tree[x].lc
	#define rc(x) tree[x].rc
	#define mx(x) tree[x].mx
	SegmentTree operator + (SegmentTree b) {
		SegmentTree ans = {0, 0, 0, {0, 0}, {0, 0}, {0, 0}, 0};
		ans.cnt = cnt + b.cnt, ans.len = len + b.len;
		ans.lc[0] = lc[0] + (lc[0] == len ? b.lc[0] : 0);
		ans.rc[0] = b.rc[0] + (b.rc[0] == b.len ? rc[0] : 0);
		ans.lc[1] = lc[1] + (lc[1] == len ? b.lc[1] : 0);
		ans.rc[1] = b.rc[1] + (b.rc[1] == b.len ? rc[1] : 0);
		ans.mx[0] = max({mx[0], b.mx[0], rc[0] + b.lc[0]});
		ans.mx[1] = max({mx[1], b.mx[1], rc[1] + b.lc[1]});
		return ans;
	}
}tree[N << 2];

void pushDown(int u) {
	if (ctag(u)) {
		rtag(l(u)) = rtag(r(u)) = false;
		cnt(l(u)) = ctag(u) == 1 ? 0 : len(l(u));
		cnt(r(u)) = ctag(u) == 1 ? 0 : len(r(u));
		lc(l(u))[1] = rc(l(u))[1] = mx(l(u))[1] = cnt(l(u));
		lc(l(u))[0] = rc(l(u))[0] = mx(l(u))[0] = len(l(u)) - cnt(l(u));
		lc(r(u))[1] = rc(r(u))[1] = mx(r(u))[1] = cnt(r(u));
		lc(r(u))[0] = rc(r(u))[0] = mx(r(u))[0] = len(r(u)) - cnt(r(u));
		ctag(l(u)) = ctag(r(u)) = ctag(u), ctag(u) = 0;
	}
	if (rtag(u)) {
		rtag(u) ^= 1, rtag(l(u)) ^= 1, rtag(r(u)) ^= 1;
		swap(lc(l(u))[0], lc(l(u))[1]), swap(rc(l(u))[0], rc(l(u))[1]);
		swap(lc(r(u))[0], lc(r(u))[1]), swap(rc(r(u))[0], rc(r(u))[1]);
		swap(mx(l(u))[0], mx(l(u))[1]), swap(mx(r(u))[0], mx(r(u))[1]);
		cnt(l(u)) = len(l(u)) - cnt(l(u)), cnt(r(u)) = len(r(u)) - cnt(r(u));
	}
}

void build(int u, int tl, int tr) {
	if (tl == tr) {
		len(u) = 1;
		cnt(u) = ary[tl];
		lc(u)[cnt(u)] = rc(u)[cnt(u)] = mx(u)[cnt(u)] = 1;
		return;
	}
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
	tree[u] = tree[l(u)] + tree[r(u)];
}

void modify(int u, int tl, int tr, int l, int r, int op) {
	if (tl >= l and tr <= r) {
		if (op == 2) {
			rtag(u) ^= 1;
			swap(mx(u)[0], mx(u)[1]);
			cnt(u) = len(u) - cnt(u);
			swap(lc(u)[0], lc(u)[1]), swap(rc(u)[0], rc(u)[1]);
		} else {
			cnt(u) = op ? tr - tl + 1 : 0;
			lc(u)[op] = rc(u)[op] = tr - tl + 1;
			lc(u)[op ^ 1] = rc(u)[op ^ 1] = 0;
			mx(u)[op] = tr - tl + 1, mx(u)[op ^ 1] = 0;
			ctag(u) = op + 1, rtag(u) = false;
		}
		return;
	}
	pushDown(u);
	int mid = tl + tr >> 1;
	if (l <= mid) modify(l(u), tl, mid, l, r, op);
	if (r > mid) modify(r(u), mid + 1, tr, l, r, op);
	tree[u] = tree[l(u)] + tree[r(u)];
}

SegmentTree query(int u, int tl, int tr, int l, int r) {
	if (tl >= l and tr <= r) return tree[u];
	pushDown(u);
	int mid = tl + tr >> 1; SegmentTree ans;
	if (l <= mid and r <= mid) ans = query(l(u), tl, mid, l, r);
	else if (l > mid and r > mid) ans = query(r(u), mid + 1, tr, l, r);
	else ans = query(l(u), tl, mid, l, r) + query(r(u), mid + 1, tr, l, r);
	return ans;
}

int main() {
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i) rd(ary[i]);
	build(1, 1, n);
	for (int i = 1, op, l, r; i <= m; ++ i) {
		rd(op), rd(l), rd(r); l ++, r ++;
		if (op <= 2) modify(1, 1, n, l, r, op);
		if (op == 3) ot(query(1, 1, n, l, r).cnt);
		if (op == 4) ot(query(1, 1, n, l, r).mx[1]);		
	}
	return 0;
}
