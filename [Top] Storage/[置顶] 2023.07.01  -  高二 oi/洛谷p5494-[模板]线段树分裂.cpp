#include <bits/stdc++.h>
#define DEBUG cout << "-- DEBUG --\n";
#define debug(x) cout << #x << ' ' << x << endl;
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

using IO::input;
using IO::output;
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
const int LOGN = 18 + 2;
int n, m;
int rt[N], tot, buf[N * LOGN];
struct SegmentTree {
	int s[2]; LL cnt;
	#define l(x) tree[x].s[0]
	#define r(x) tree[x].s[1]
	#define cnt(x) tree[x].cnt
	void init() { return s[0] = s[1] = cnt = 0, void(); }
}tree[N * LOGN];

void del(int x) { return buf[++ buf[0]] = x, void(); }
int newNode() { return buf[0] ? buf[buf[0] --] : ++ tot; }

void modify(int &u, int tl, int tr, int val, int cnt) {
	if (!u) u = newNode(), tree[u].init();
	cnt(u) += cnt;
	if (tl == tr) return;
	int mid = tl + tr >> 1;
	if (val <= mid) return modify(l(u), tl, mid, val, cnt);
	else return modify(r(u), mid + 1, tr, val, cnt);
}

LL query(int u, int tl, int tr, int ql, int qr) {
	if (tr < ql or tl > qr) return 0;
	if (tl >= ql and tr <= qr) return cnt(u);
	int mid = tl + tr >> 1;
	return query(l(u), tl, mid, ql, qr) + query(r(u), mid + 1, tr, ql, qr);
}

int getVal(int u, int tl, int tr, int rk) {
	if (cnt(u) < rk) return -1;
	if (tl == tr) return tl;
	int mid = tl + tr >> 1;
	if (rk <= cnt(l(u))) return getVal(l(u), tl, mid, rk);
	else return getVal(r(u), mid + 1, tr, rk - cnt(l(u)));
}

int merge(int x, int y) {
	if (!x or !y) return x | y;
	cnt(x) += cnt(y);
	l(x) = merge(l(x), l(y));
	r(x) = merge(r(x), r(y));
	del(y);
	return x;
}

void split(int x, int &y, LL rk) {
	if (!x) return;
	y = newNode(), tree[y].init();
	if (rk > cnt(l(x))) split(r(x), r(y), rk - cnt(l(x)));
	else swap(r(x), r(y));
	if (rk < cnt(l(x))) split(l(x), l(y), rk);
	cnt(y) = cnt(x) - rk, cnt(x) = rk;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.in", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif
	input(n), input(m);
	rt[0] = 1;
	for (int i = 1, x; i <= n; ++ i) {
		input(x);
		modify(rt[1], 1, n, i, x);
	}
	for (int i = 1, op, p, x, y, tmp; i <= m; ++ i) {
		input(op), input(p), input(x);
		if (op == 0) {
			input(y);
			LL ka = query(rt[p], 1, n, 1, x - 1), kb = query(rt[p], 1, n, x, y);
			split(rt[p], rt[++ rt[0]], ka);
			split(rt[rt[0]], tmp, kb);
			rt[p] = merge(rt[p], tmp);
		} else if (op == 1) {
			rt[p] = merge(rt[p], rt[x]);
		} else if (op == 2) {
			input(y);
			modify(rt[p], 1, n, y, x);
		} else if (op == 3) {
			input(y);
			output(query(rt[p], 1, n, x, y));
		} else if (op == 4) {
			output(getVal(rt[p], 1, n, x));
		}
	}
	return 0;
}
