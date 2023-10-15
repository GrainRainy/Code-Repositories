#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
LL n, m, q, op, l, r, x, tg[N], tim[N];
LL qtp, ans[N], otp;
struct Query {
	LL id, tm, op, l, r, x;
	bool operator < (const Query &t) const {
		if (tm ^ t.tm) return tm < t.tm;
		return op < t.op;
	}
}sv[N << 1];

struct Fenwick {
	LL tr[N];
	void add(int p, LL x) { while (p <= m) tr[p] += x, p += p & -p; }
	LL query(int p) { LL r = 0; while (p) r += tr[p], p -= p & -p; return r; }
}t;

int main() {
//	freopen("b.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= q; ++ i) {
		cin >> op >> l >> r;
		if (op == 1) {
			cin >> x;
			sv[++ qtp] = {i, i, op, l, r, x};
		} else if (op == 2) {
			tim[l] = i;
			sv[++ qtp] = {i, i, op, l, 0, r};
		} else if (op == 3) {
			sv[++ qtp] = {++ otp, tim[l], op, l, r, -1};
			sv[++ qtp] = {otp, i, op, l, r, 1};
		}
	}
	sort(sv + 1, sv + qtp + 1);
	for (int i = 1; i <= qtp; ++ i) {
		if (sv[i].op == 1) t.add(sv[i].l, sv[i].x), t.add(sv[i].r + 1, -sv[i].x);
		if (sv[i].op == 2) tg[sv[i].l] = sv[i].x;
		if (sv[i].op == 3) {
			ans[sv[i].id] += t.query(sv[i].r) * sv[i].x;
			if (sv[i].x == 1) ans[sv[i].id] += tg[sv[i].l];
		}
	}
	for (int i = 1; i <= otp; ++ i) cout << ans[i] << '\n';
	return 0;
}
