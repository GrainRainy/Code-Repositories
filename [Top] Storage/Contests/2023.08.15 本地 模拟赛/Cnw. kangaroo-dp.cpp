#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e3 + 10;
const int MOD = 1e9 + 7;
int n, s, t;
int dp[N][N];

inline void upd(int &x, int y) {
	x += y;
	(x >= MOD) and (x -= MOD);
}

int main() {
	scanf("%d%d%d", &n, &s, &t);
	dp[1][1] = 1;
	for (int i = 2; i <= n; ++ i) {
		for (int j = 1; j <= i; ++ j) {
			if (i == s or i == t) {
				upd(dp[i][j], dp[i - 1][j]);
				upd(dp[i][j], dp[i - 1][j - 1]);
			} else {
				upd(dp[i][j], (LL)dp[i - 1][j + 1] * j % MOD);
				upd(dp[i][j], (LL)dp[i - 1][j - 1] * (j - (i > s) - (i > t)) % MOD);
			}
		}
	}
	return printf("%d\n", dp[n][1]), 0;
} 
