#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
int n, m, a[N];
struct segt {
	long long sm;
	int len, lv, rv, lc, rc;
	#define l(x) ((x) << 1)
	#define r(x) ((x) << 1 | 1)
	#define sm(x) tree[x].sm
	#define len(x) tree[x].len
	#define lv(x) tree[x].lv
	#define rv(x) tree[x].rv
	#define lc(x) tree[x].lc
	#define rc(x) tree[x].rc
	segt operator + (const segt &t) const {
		segt res;
		res.sm = sm + t.sm + ((rv <= t.lv) ? (LL)rc * t.lc : 0);
		res.len = len + t.len;
		res.lv = lv, res.rv = t.rv;
		res.lc = lc == len and rv <= t.lv ? len + t.lc : lc;
		res.rc = t.rc == t.len and rv <= t.lv ? rc + t.len : t.rc;
		return res;
	}
}tree[N << 2];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

void build(int u, int tl, int tr) {
	if (tl == tr) return tree[u] = {1, 1, a[tl], a[tl], 1, 1}, void();
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
	tree[u] = tree[l(u)] + tree[r(u)];
}

void modify(int u, int tl, int tr, int p, int v) {
	if (tl == tr) return tree[u] = {1, 1, v, v, 1, 1}, void();
	int mid = tl + tr >> 1;
	if (p <= mid) modify(l(u), tl, mid, p, v);
	else modify(r(u), mid + 1, tr, p, v);
	tree[u] = tree[l(u)] + tree[r(u)];
}

segt query(int u, int tl, int tr, int l, int r) {
	if (l > tr or r < tl) return {0, 0, 0, 0, 0};
	if (l <= tl and tr <= r) return tree[u];
	int mid = tl + tr >> 1;
	return query(l(u), tl, mid, l, r) + query(r(u), mid + 1, tr, l, r);
}

int main() {
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i) rd(a[i]);
	build(1, 1, n);
	for (int i = 1, op, x, y; i <= m; ++ i) {
		rd(op), rd(x), rd(y);
		if (op == 1) modify(1, 1, n, x, y); 
		if (op == 2) ot(query(1, 1, n, x, y).sm);
	}
	return 0;
}
