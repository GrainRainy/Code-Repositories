#include <bits/stdc++.h>
using namespace std;
const int L = 10 + 5;
const int N = 1e4 + 10;
int n, m, num[L];
int cnt[L] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int w[N], dp[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(dp, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= m; ++ i) cin >> num[i];
	sort(num + 1, num + 1 + m, greater<int>());
	dp[0] = 0;
	for (int i = 1; i <= m; ++ i) {
		w[i] = cnt[num[i]];
		for (int j = w[i]; j <= n; ++ j) 
			dp[j] = max(dp[j], dp[j - w[i]] + 1);
	}

	while (n) {
		for (int i = 1; i <= m; ++ i) 
			if (n >= w[i] and dp[n - w[i]] == dp[n] - 1) {
				n -= w[i];
				cout << num[i];
				break;
			}
	}
	return 0;
}

