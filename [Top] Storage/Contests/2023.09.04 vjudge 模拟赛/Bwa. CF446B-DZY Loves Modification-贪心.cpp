#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
}

using IO::rd;
using namespace std;
using LL = long long;
const int N = 1e3 + 10;
int n, m, k, p, pos;
LL a[N << 1];
struct SegmentTree {
	LL mx, sm, tg;
	#define l(x) ((x) << 1)
	#define r(x) ((x) << 1 | 1)
	#define mx(x) tree[x].mx
	#define sm(x) tree[x].sm
	#define tg(x) tree[x].tg
}tree[N * 2 << 2];
LL ans;

inline void pushup(int u) {
	mx(u) = max(mx(l(u)), mx(r(u)));
	sm(u) = sm(l(u)) + sm(r(u));
}

inline void pushdown(int u, int tl, int tr) {
	if (!tg(u)) return;
	int mid = tl + tr >> 1;
	sm(l(u)) += (mid - tl + 1) * tg(u);
	sm(r(u)) += (tr - mid) * tg(u);
	mx(l(u)) += tg(u), mx(r(u)) += tg(u);
	tg(l(u)) += tg(u), tg(r(u)) += tg(u);
	tg(u) = 0;
}

void build(int u, int tl, int tr) {
	if (tl == tr) return sm(u) = mx(u) = a[tl], void();
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
	pushup(u);
}

void modify(int u, int tl, int tr, int l, int r, LL val) {
	if (tl >= l and tr <= r) {
		sm(u) += (tr - tl + 1) * val;
		mx(u) += val;
		tg(u) += val;
		return;
	}
	int mid = tl + tr >> 1;
	pushdown(u, tl, tr);
	if (l <= mid) modify(l(u), tl, mid, l, r, val);
	if (r > mid) modify(r(u), mid + 1, tr, l, r, val);
	pushup(u);
}

int query(int u, int tl, int tr, int val) {
	if (tl == tr) return tl;
	int mid = tl + tr >> 1;
	pushdown(u, tl, tr);
	if (mx(l(u)) == val) return query(l(u), tl, mid, val);
	else return query(r(u), mid + 1, tr, val);
}

int main() {
	rd(n), rd(m), rd(k), rd(p);
	for (int i = 1, tmp; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			rd(tmp), a[i] += tmp, a[n + j] += tmp;
	build(1, 1, n + m);
	while (k --) {
		ans += mx(1);
		pos = query(1, 1, n + m, mx(1));
		if (pos <= n) {
			modify(1, 1, n + m, pos, pos, -p * m);
			modify(1, 1, n + m, n + 1, n + m, -p);
		} else {
			modify(1, 1, n + m, pos, pos, -p * n);
			modify(1, 1, n + m, 1, n, -p);
		}
	}
	return cout << ans << '\n', 0;
}
