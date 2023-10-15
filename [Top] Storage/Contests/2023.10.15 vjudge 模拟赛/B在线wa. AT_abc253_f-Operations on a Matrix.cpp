#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' '  << x << '\n';
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
const int LN = 20;
LL n, m, q, op, l, r, x, tg[N], tim[N];
int rt[N], id[N], qtp, ttp;
struct Segment {
	int l, r;
	LL tg;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define tg(v) tree[x].tg
}tree[N * LN];

int insert(int pre, int tl, int tr, int l, int r, LL x) {
	int nw = ++ ttp;
	cout << "there " << nw << ' ' << tl << ' ' << tr << '\n';
	tree[nw] = tree[pre];
	if (l <= tl and tr <= r) {
		tg(nw) += x;
		return nw;
	}
	int mid = tl + tr >> 1;
	if (l <= mid) l(nw) = insert(l(pre), tl, mid, l, r, x);
	if (r > mid) r(nw) = insert(r(pre), mid + 1, tr, l, r, x);
}

LL query(int u, int tl, int tr, int p) {
	if (!u or tl == tr) return 0;
	int mid = tl + tr >> 1;
	if (p <= mid) return query(l(u), tl, mid, p) + tg(u);
	else return query(r(u), mid + 1, tr, p) + tg(u);
}

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= q; ++ i) {
		cin >> op >> l >> r;
		if (op == 1) {
			cin >> x;
			id[++ qtp] = i;
			rt[qtp] = insert(rt[qtp - 1], 1, m, l, r, x);
		} else if (op == 2) {
			tg[l] = r, tim[l] = i;
		} else if (op == 3) {
			int *tmp = lower_bound(id + 1, id + qtp + 1, tim[l]);
			cout << tg[l] + query(rt[qtp], 1, m, r) - query(rt[*(--tmp)], 1, m, r) << '\n';
		}
	}
	return 0;
}
