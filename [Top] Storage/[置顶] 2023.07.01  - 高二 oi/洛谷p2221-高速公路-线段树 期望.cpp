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
const int N = 1e5 + 10;
int n, m;
char op[3];
struct SegmentTree {
	LL sw, swi, swii, si, sii, tag;
	#define sw(u) tree[u].sw
	#define swi(u) tree[u].swi
	#define swii(u) tree[u].swii
	#define si(u) tree[u].si
	#define sii(u) tree[u].sii
	#define tag(u) tree[u].tag
	SegmentTree operator + (const SegmentTree &t) const {
		SegmentTree res;
		res = {
			sw + t.sw, swi + t.swi, swii + t.swii,
			si + t.si, sii + t.sii, 0
		};
		return res;
	}
}tree[N << 2];

void pushDown(int u, int tl, int tr) {
	if (!tag(u)) return;
	int mid = tl + tr >> 1;
	sw(l(u)) += tag(u) * (mid - tl + 1), sw(r(u)) += tag(u) * (tr - mid);
	swi(l(u)) += tag(u) * si(l(u)), swi(r(u)) += tag(u) * si(r(u));
	swii(l(u)) += tag(u) * sii(l(u)), swii(r(u)) += tag(u) * sii(r(u));
	tag(l(u)) += tag(u), tag(r(u)) += tag(u);
	tag(u) = 0;
}

void build(int u, int tl, int tr) {
	if (tl == tr) return tree[u] = {0, 0, 0, tl, /*note*/(LL)tl * tl, 0}, void();
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
	tree[u] = tree[l(u)] + tree[r(u)];
}

void modify(int u, int tl, int tr, int l, int r, int val) {
	if (tl >= l and tr <= r) {
		sw(u) += (tr - tl + 1) * val;
		swi(u) += si(u) * val;
		swii(u) += sii(u) * val;
		tag(u) += val;
		return;
	}
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	if (l <= mid) modify(l(u), tl, mid, l, r, val);
	if (r > mid) modify(r(u), mid + 1, tr, l, r, val);
	tree[u] = tree[l(u)] + tree[r(u)];
}

LL query(int u, int tl, int tr, int l, int r) {
	if (tl > r or tr < l) return 0;
	if (tl >= l and tr <= r)
		return (r + 1 - (LL)(r + 1) * l) * sw(u) + (l + r) * swi(u) - swii(u);
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	return query(l(u), tl, mid, l, r) + query(r(u), mid + 1, tr, l, r);
}

int main() {
	input(n), input(m);
	build(1, 1, n);
	LL tmpa, tmpb, gd;
	for (int i = 1, l, r, x; i <= m; ++ i) {
		cin >> op; input(l), input(r);
		if (*op == 'C') input(x), modify(1, 1, n, l, r - 1, x);
		if (*op == 'Q') {
			tmpa = query(1, 1, n, l, r - 1); tmpa <<= 1;
			tmpb = /*note*/(LL)(r - l + 1) * (r - l);
			gd = __gcd(tmpa, tmpb);
			output(tmpa / gd, '/'), output(tmpb / gd);
		}
	}
	return 0;
}
