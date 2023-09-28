#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 3e5 + 10;
LL n, k, s[N], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) cin >> s[i], s[i] += s[i - 1];
	sort(s + 1, s + n);
	for (int i = 1; i < k; ++ i) ans -= s[i];
	return cout << ans + k * s[n] << '\n', 0;
}
