#include <bits/stdc++.h>
#define fi first
#define se second
#define lson (rt << 1)
#define rson (rt << 1 | 1)
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

using namespace std;
using namespace IO;
using D = double;
using PDI = pair<D, int>;
const int N = 1e5 + 10;
const int SX = 39989, SY = 1e9;
const int T = 4e4;
const D eps = 1e-9;
int n, lastans, op, qxa, qya, qxb, qyb;
struct Segment { D k, b; }a[N];
int tree[N + (T << 1)], top;

int cmp(D x, D y) {
// bigger return 1, smaller return -1, equal return 0
	if (x - y > eps) return 1;
	if (y - x > eps) return -1;
	return 0;
}

PDI pMax(PDI a, PDI b) {
	if (cmp(a.fi, b.fi) == -1) return b;
	if (cmp(a.fi, b.fi) == 1) return a;
	return a.se < b.se ? a : b;
}

D calc(int i, int x) { return a[i].k * x + a[i].b; }

void add(int xa, int ya, int xb, int yb) {
	if (xa == xb) a[++ top].k = 0, a[top].b = max(ya, yb);
	else {
		a[++ top].k = (D)(yb - ya) / (xb - xa), 
		a[top].b = ya - a[top].k * xa;	
	}
	return;
}

void pushDown(int rt, int tl, int tr, int u) {
	int &v = tree[rt], mid = tl + tr >> 1;
	if (cmp(calc(u, mid), calc(v, mid)) == 1) swap(u, v);
	int bl = cmp(calc(u, tl), calc(v, tl));
	int br = cmp(calc(u, tr), calc(v, tr));
	if (bl == 1 or (!bl and u < v)) pushDown(lson, tl, mid, u);
	if (br == 1 or (!br and u < v)) pushDown(rson, mid + 1, tr, u);
}

void cover(int rt, int tl, int tr, int l, int r, int u) {
	if (l <= tl and r >= tr) return pushDown(rt, tl, tr, u);
	int mid = tl + tr >> 1;
	if (l <= mid) cover(lson, tl, mid, l, r, u);
	if (r > mid) cover(rson, mid + 1, tr, l, r, u);
}

PDI query(int rt, int l, int r, int x) {
	if (l > x or r < x) return {0, 0};
	int mid = l + r >> 1;
	D res = calc(tree[rt], x);
	if (l == r) return {res, tree[rt]};
	return pMax({res, tree[rt]}, pMax(query(lson, l, mid, x), query(rson, mid + 1, r, x)));
}

int main() {
	input(n);
	while (n --) {
		input(op);
		if (op == 1) {
			input(qxa), input(qya), input(qxb), input(qyb);
			qxa = (qxa + lastans - 1 + SX) % SX + 1;
			qxb = (qxb + lastans - 1 + SX) % SX + 1;
			qya = (qya + lastans - 1 + SY) % SY + 1;
			qyb = (qyb + lastans - 1 + SY) % SY + 1;
			if (qxa > qxb) swap(qxa, qxb), swap(qya, qyb);
			add(qxa, qya, qxb, qyb);
			cover(1, 1, SX, qxa, qxb, top);
		} else {
			input(qxa);
			qxa = (qxa + lastans - 1 + SX) % SX + 1;
			output(lastans = query(1, 1, SX, qxa).se);
		}
	}
	return 0;
}
