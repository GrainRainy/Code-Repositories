#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n, m, a[N];
long long dp[2][N][2];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int main() {
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i) rd(a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; ++ i) a[i] = a[i + 1] - a[i];
	memset(dp, 0x3f, sizeof dp), dp[0][0][0] = 0;
	for (int i = 1; i < n; ++ i)
		for (int j = min(i, m); ~j; -- j) {
			dp[i & 1][j][0] = min(dp[i - 1 & 1][j][0], dp[i - 1 & 1][j][1]);
			dp[i & 1][j][1] = dp[i - 1 & 1][j - 1][0] + a[i];
		}
	return cout << min(dp[n - 1 & 1][m][0], dp[n - 1 & 1][m][1]) << '\n', 0;
}
