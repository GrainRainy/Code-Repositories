#include <bits/stdc++.h>
#define l(u) ((u) << 1)
#define r(u) ((u) << 1 | 1)
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
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
const int N = 5e5 + 10;
const int INF = 1e9 + 5e8 + 10;
int n, m, a[N];
struct SegmentTree {
	LL sum;
	// elements: h->history, t->tag, c->cnt, n->not
	int mx, se, hmx, cmx, tmx, htmx, tnmx, htnmx;
	#define mx(u) tree[u].mx
	#define se(u) tree[u].se
	#define sum(u) tree[u].sum
	#define hmx(u) tree[u].hmx
	#define cmx(u) tree[u].cmx
	#define tmx(u) tree[u].tmx
	#define htmx(u) tree[u].htmx
	#define tnmx(u) tree[u].tnmx
	#define htnmx(u) tree[u].htnmx
}tree[N << 2];

void pushUp(int u) {
	sum(u) = sum(l(u)) + sum(r(u));
	hmx(u) = max(hmx(l(u)), hmx(r(u)));
	if (mx(l(u)) == mx(r(u))) {
		mx(u) = mx(l(u));
		se(u) = max(se(l(u)), se(r(u)));
		cmx(u) = cmx(l(u)) + cmx(r(u));
	} else if (mx(l(u)) > mx(r(u))) {
		mx(u) = mx(l(u));
		se(u) = max(se(l(u)), mx(r(u)));
		cmx(u) = cmx(l(u));
	} else {
		mx(u) = mx(r(u));
		se(u) = max(mx(l(u)), se(r(u)));
		cmx(u) = cmx(r(u));
	}
}

void update(int u, int tl, int tr, int tmx, int htmx, int tnmx, int htnmx) {
	sum(u) += (LL)tmx * cmx(u) + (LL)tnmx * (tr - tl + 1 - cmx(u));
	hmx(u) = max(hmx(u), mx(u) + htmx);
	htmx(u) = max(htmx(u), tmx(u) + htmx);
	mx(u) += tmx, tmx(u) += tmx;
	htnmx(u) = max(htnmx(u), tnmx(u) + htnmx);
	if (se(u) != -INF) se(u) += tnmx;
	tnmx(u) += tnmx;
}

void pushDown(int u, int tl, int tr) {
	int mid = tl + tr >> 1, mx = max(mx(l(u)), mx(r(u)));
	if (mx(l(u)) == mx) update(l(u), tl, mid, tmx(u), htmx(u), tnmx(u), htnmx(u));
	else update(l(u), tl, mid, tnmx(u), htnmx(u), tnmx(u), htnmx(u));
	if (mx(r(u)) == mx) update(r(u), mid + 1, tr, tmx(u), htmx(u), tnmx(u), htnmx(u));
	else update(r(u), mid + 1, tr, tnmx(u), htnmx(u), tnmx(u), htnmx(u));
	tmx(u) = htmx(u) = tnmx(u) = htnmx(u) = 0;
}

void build(int u, int tl, int tr) {
	if (tl == tr) {
		sum(u) = mx(u) = hmx(u) = a[tl];
		se(u) = -INF, cmx(u) = 1;
		return;
	}
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
	pushUp(u);
}

void add(int u, int tl, int tr, int l, int r, int val) {
	if (tl >= l and tr <= r) return update(u, tl, tr, val, val, val, val);
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	if (l <= mid) add(l(u), tl, mid, l, r, val);
	if (r > mid) add(r(u), mid + 1, tr, l, r, val);
	pushUp(u);
}

void mn(int u, int tl, int tr, int l, int r, int val) {
	if (tl > r or tr < l or val >= mx(u)) return;
	if (tl >= l and tr <= r and val > se(u))
		return update(u, tl, tr, val - mx(u), val - mx(u), 0, 0);
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	mn(l(u), tl, mid, l, r, val), mn(r(u), mid + 1, tr, l, r, val);
	pushUp(u);
}

LL querySum(int u, int tl, int tr, int l, int r) {
	if (tl > r or tr < l) return 0;
	if (tl >= l and tr <= r) return sum(u);
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	return querySum(l(u), tl, mid, l, r) + querySum(r(u), mid + 1, tr, l, r);
}

int queryNmx(int u, int tl, int tr, int l, int r) {
	if (tl > r or tr < l) return -INF;
	if (tl >= l and tr <= r) return mx(u);
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	return max(queryNmx(l(u), tl, mid, l, r), queryNmx(r(u), mid + 1, tr, l, r));
}

int queryHmx(int u, int tl, int tr, int l, int r) {
	if (tl > r or tr < l) return -INF;
	if (tl >= l and tr <= r) return hmx(u);
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	return max(queryHmx(l(u), tl, mid, l, r), queryHmx(r(u), mid + 1, tr, l, r));
}

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) input(a[i]);
	build(1, 1, n);
	for (int i = 1, op, l, r, k; i <= m; ++ i) {
		input(op), input(l), input(r); if (op <= 2) input(k);
		if (op == 1) add(1, 1, n, l, r, k);
		if (op == 2) mn(1, 1, n, l, r, k);
		if (op == 3) output(querySum(1, 1, n, l, r));
		if (op == 4) output(queryNmx(1, 1, n, l, r));
		if (op == 5) output(queryHmx(1, 1, n, l, r));
	}
	return 0;
}
