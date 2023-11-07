#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e6 + 10;
const int SN = 3e3 + 10;
int n, k, res;
LL d[N], dp[SN][SN][2], ansa, ansb, ans = 0x3f3f3f3f3f3f3f3f;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
} 

void dynamic() {
	memset(dp, 0x3f, sizeof dp), dp[k][k][0] = dp[k][k][1] = 0;
	for (int len = 2; len <= n; ++ len)
		for (int l = 1, r = len; r <= n; ++ l, ++ r) {
			dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][0] + (d[l + 1] - d[l]) * (n - r + l));
			dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][1] + (d[r] - d[l]) * (n - r + l));
			dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][0] + (d[r] - d[l]) * (n - r + l));
			dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][1] + (d[r] - d[r - 1]) * (n - r + l));
		}
	ans = min(dp[1][n][0], dp[1][n][1]);
}

int main() {
	rd(n), rd(k), res = n - 1;
	for (int i = 2; i <= n; ++ i) rd(d[i]), d[i] += d[i - 1];
	for (int i = k - 1; i > 0; -- i) ansa += (d[i + 1] - d[i]) * res, res --;
	ansa += d[k + 1] * res, res --;
	for (int i = k + 2; i <= n; ++ i) ansa += (d[i] - d[i - 1]) * res, res --;
	res = n - 1;
	for (int i = k + 1; i <= n; ++ i) ansb += (d[i] - d[i - 1]) * res, res --;
	ansb += (d[n] - d[k - 1]) * res, res --;
	for (int i = k - 2; i > 0; -- i) ansb += (d[i + 1] - d[i]) * res, res --;
	if (n <= 3e3) dynamic();
	return cout << min({ansa, ansb, ans}) << '\n', 0;
}
