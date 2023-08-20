#include <bits/stdc++.h>
using namespace std;

void solve() {
	int m, k, a, b;
	cin >> m >> k >> a >> b;
	int aa = m % k, bb = m / k;
	if (a >= aa) {
		a -= aa, b += a / k;
		cout << max(0, bb - b) << '\n';
	} else cout << max(0, bb - b) + aa - a << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
