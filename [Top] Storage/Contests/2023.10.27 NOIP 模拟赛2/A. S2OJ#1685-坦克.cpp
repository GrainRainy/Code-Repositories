#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL n, m, a, b, ra, rb;

void solve() {
	cin >> n >> m >> b >> a;
	ra = a, rb = b;
	while (n and m) {
		LL k = min((ra - 1) / m, (rb - 1) / n), tn = n, tm = m;
		ra -= k * m, rb -= k * n;
		if (tm < ra) ra -= tm;
		else {
			n = max(0ll, tn - (tm - ra) / a - 1);
			ra = a - (tm - ra) % a;
		}
		if (tn < rb) rb -= tn;
		else {
			m = max(0ll, tm - (tn - rb) / b - 1);
			rb = b - (tn - rb) % b;
		}
	}
	cout << n << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
//	cerr << "sol with time " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}
