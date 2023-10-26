#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, s[N];
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++ i) cin >> s[i];
	for (int del = 1; del < n - 2; ++ del) {
		long long v = 0;
		for (int k = 1; k <= (n - 1) / del; ++ k) {
			long long a = n - 1 - (long long)k * del;
			if (a <= del or !(a % del) and a / del <= k) break;
			ans = max(ans, v += s[del * k] + s[a]);
		}
	}
	return cout << ans << '\n', 0;
}
