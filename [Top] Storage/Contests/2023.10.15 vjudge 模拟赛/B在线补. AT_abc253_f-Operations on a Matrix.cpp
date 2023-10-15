#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' '  << x << '\n';
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
const int LN = 40;
LL n, m, q, op, l, r, x, tg[N], tim[N];
int rt[N], qtp, ttp;
struct Segment {
	int l, r;
	LL tg;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define tg(x) tree[x].tg
}tree[N * LN];

int insert(int pre, int tl, int tr, int l, int r, LL x) {
	int nw = ++ ttp;
	tree[nw] = tree[pre];
	if (l <= tl and tr <= r) return tg(nw) += x, nw;	
	int mid = tl + tr >> 1;
	if (l <= mid) l(nw) = insert(l(pre), tl, mid, l, r, x);
	if (r > mid) r(nw) = insert(r(pre), mid + 1, tr, l, r, x);
	return nw;
}

LL query(int u, int tl, int tr, int p) {
	if (!u) return 0;
	if (tl == tr) return tg(u);
	int mid = tl + tr >> 1;
	if (p <= mid) return query(l(u), tl, mid, p) + tg(u);
	else return query(r(u), mid + 1, tr, p) + tg(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= q; ++ i) {
		cin >> op >> l >> r;
		if (op == 1) {
			cin >> x;
			rt[i] = insert(rt[i - 1], 1, m, l, r, x);
		} else if (op == 2) {
			tg[l] = r, tim[l] = i, rt[i] = rt[i - 1];
		} else if (op == 3) {
			rt[i] = rt[i - 1];
			cout << tg[l] + query(rt[i], 1, m, r) - query(rt[tim[l]], 1, m, r) << '\n';
		}
	}
	return 0;
}
