#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int t, n, b;
long long del, tmp, ans;
map<long long, long long> f;

void solve() {
	cin >> n;
	del = tmp = 0, ans = 1, f.clear();
	f[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		cin >> b;
		del -= b, tmp = ans - f[b + del], f[b + del] = ans;
		ans = (ans + tmp) % MOD;
	}
	cout << (ans + MOD) % MOD << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t --) solve();
}
