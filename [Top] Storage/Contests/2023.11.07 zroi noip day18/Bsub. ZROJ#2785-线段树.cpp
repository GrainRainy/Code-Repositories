#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL MOD = 1e9 + 7;
LL n, l, r, dep;

#define l(u) ((u) << 1)
#define r(u) ((u) << 1 | 1)
namespace sub2 {
	LL calc(LL x, LL dp) {
		LL res = 0;
		for (LL i = 1; i <= dp; ++ i) {
			res += x * (1ll << i - 1) * (1ll << i - 1), res %= MOD;
			res += ((1 << i - 1) - 1) * (1ll << i - 1) / 2, res %= MOD;
		}
		return res;
	}
	
	LL solve(LL u, LL tl, LL tr, LL l, LL r) {
		if (tl > r or tr < l) return 0;
		if (l <= tl and tr <= r) return calc(u, (LL)log2(n) - (LL)log2(u) + 1);
		LL mid = tl + tr >> 1;
		return (solve(l(u), tl, mid, l, r) + solve(r(u), mid + 1, tr, l, r)) % MOD;
	}
}

LL build(LL u, LL tl, LL tr, LL l, LL r) {
	if (tl == tr) return u * (bool)(l <= tl and tr <= r);
	LL mid = tl + tr >> 1;
	return (build(l(u), tl, mid, l, r) + build(r(u), mid + 1, tr, l, r) + u * (bool)(l <= tl and tr <= r)) % MOD;
}

void solve() {
	cin >> n >> l >> r, dep = log2(n);
	if (1ll << dep == n) cout << sub2::solve(1, 1, n, l, r) << '\n';
	else cout << build(1, 1, n, l, r) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
