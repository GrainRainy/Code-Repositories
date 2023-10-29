#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, a[N];
long long ans;

void solve() {
	cin >> n, ans = 0;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	for (int i = 1; i <= n; ++ i)
		for (int j = i + 1; j <= n; ++ j)
			if (__gcd(a[i], a[j]) == (a[i] ^ a[j]))
//				cout << i << ' ' << j << '\n';
				ans ++;
	cout << ans << '\n';
}

int main() {
//	freopen("a.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
