#include <bits/stdc++.h>
#define int long long
using namespace std;
using LL = long long;
const int N = 5e4 + 10;
LL n, q, a[N], b[N], ans;

signed main() {
//	freopen("ex_expedition3.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	for (int i = 1; i <= n; ++ i) cin >> b[i];
	cin >> q;
	for (int i = 1, l, r, x; i <= q; ++ i) {
		cin >> l >> r >> x;
		LL res = 0;
		for (int j = l; j <= r; ++ j) {
			if ((x | a[j]) == x) x -= a[j], res += b[j];
		}
		ans ^= res;
		cout << res << '\n';
	}
//	cout << ans << '\n';
	return 0;
}
