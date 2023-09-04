#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MOD = 1e9 + 7;
LL n, l[100], ans;

void solve() {
	cin >> n; ans = 0;
	for (int i = 2; l[i - 1] <= n; ++ i)
		ans = (ans + i * (n / l[i - 1] - n / l[i])) % MOD;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	l[1] = 1;
	for (int i = 2; i <= 41; ++ i)
		l[i] = l[i - 1] * i / __gcd(l[i - 1], (LL)i);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
