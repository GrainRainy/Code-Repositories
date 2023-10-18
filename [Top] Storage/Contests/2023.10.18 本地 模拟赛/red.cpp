#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 3e5 + 10;
int t, n, a[N], f[N], ans;

int calc(int x) {
	if (!x or x == 1 or x == 2) return 0;
	if (f[x]) return f[x];
	return f[x] = calc(((x - 1) >> 1) + 1) + ((x - 1) >> 1);
}

void solve() {
	cin >> n, ans = n;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	int len = 0, p = 1e9;
	for (int i = 2; i <= n; ++ i) {
		if (a[i] - a[i - 1] != p) {
			ans -= calc(len);
			p = a[i] - a[i - 1], len = 2;
		} else len ++;
	}
	ans -= calc(len);
	return cout << ans << '\n', void();
}

int main() {
	freopen("red.in", "r", stdin);
	freopen("red.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t --) solve();
	return 0;
}
