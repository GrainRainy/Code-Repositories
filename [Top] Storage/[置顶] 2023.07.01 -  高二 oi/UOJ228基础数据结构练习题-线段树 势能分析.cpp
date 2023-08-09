#include <bits/stdc++.h>
#define l(x) (x << 1)
#define r(x) (x << 1 | 1)
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
int n, m, a[N];
struct SegmentTree {
	LL mx, mn, tag, sum;
	#define mx(x) tree[x].mx
	#define mn(x) tree[x].mn
	#define tag(x) tree[x].tag
	#define sum(x) tree[x].sum
}tree[N << 2];

void pushUp(int u) {
	sum(u) = sum(l(u)) + sum(r(u));
	mx(u) = max(mx(l(u)), mx(r(u)));
	mn(u) = min(mn(l(u)), mn(r(u)));
}

void pushDown(int u, int tl, int tr) {
	if (!tag(u)) return;
	int mid = tl + tr >> 1;
	sum(l(u)) += tag(u) * (mid - tl + 1);
	sum(r(u)) += tag(u) * (tr - mid);
	mx(l(u)) += tag(u), mx(r(u)) += tag(u);
	mn(l(u)) += tag(u), mn(r(u)) += tag(u);
	tag(l(u)) += tag(u), tag(r(u)) += tag(u);
	tag(u) = 0;
}

void build(int u, int tl, int tr) {
	if (tl == tr) return mx(u) = mn(u) = sum(u) = a[tl], void();
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
	pushUp(u);
}

void modify(int u, int tl, int tr, int l, int r, LL val) {
	if (tl >= l and tr <= r) {
		sum(u) += val * (tr - tl + 1);
		mn(u) += val, mx(u) += val;
		tag(u) += val;
		return;
	}
	int mid = tl + tr >> 1;
	pushDown(u, tl, tr);
	if (l <= mid) modify(l(u), tl, mid, l, r, val);
	if (r > mid) modify(r(u), mid + 1, tr, l, r, val);
	pushUp(u);
}

void sqr(int u, int tl, int tr, int l, int r) {
	if (tl >= l and tr <= r and mx(u) - (int)sqrt(mx(u)) == mn(u) - (int)sqrt(mn(u)))
		return modify(u, tl, tr, tl, tr, (int)sqrt(mx(u)) - mx(u));
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	if (l <= mid) sqr(l(u), tl, mid, l, r);
	if (r > mid) sqr(r(u), mid + 1, tr, l, r);
	pushUp(u);
}

LL query(int u, int tl, int tr, int l, int r) {
	if (tl > r or tr < l) return 0;
	if (tl >= l and tr <= r) return sum(u);
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	return query(l(u), tl, mid, l, r) + query(r(u), mid + 1, tr, l, r);
}

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) input(a[i]);
	build(1, 1, n);
	for (int i = 1, op, l, r, x; i <= m; ++ i) {
		input(op), input(l), input(r);
		if (op == 1) input(x), modify(1, 1, n, l, r, x);
		if (op == 2) sqr(1, 1, n, l, r);
		if (op == 3) output(query(1, 1, n, l, r));
	}
	return 0;
}
