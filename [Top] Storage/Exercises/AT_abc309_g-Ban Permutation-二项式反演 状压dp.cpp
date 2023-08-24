#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
using namespace std;
using LL = long long;
const int N = 100 + 10;
const int X = 5 + 1;
const int MOD = 998244353;
int n, x;
int fac[N], dp[N][N][1 << (X << 1)], ans;

void upd(int &x, int y) {
	x += y; (x >= MOD) and (x -= MOD);
}

int main() {
	scanf("%d%d", &n, &x); x --;
	dp[0][0][0] = fac[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		fac[i] = (LL)fac[i - 1] * i % MOD;
		for (int j = 0; j < i; ++ j) {
			for (int s = 0, t; s < (1 << (x << 1) + 1); ++ s) {
				if (!dp[i - 1][j][s]) continue;
				t = s >> 1;
				upd(dp[i][j][t], dp[i - 1][j][s]);
				for (int k = 0; k <= x << 1; ++ k)
					if ((~t) & (1 << k)) {
						if (i + k - x < 1 or i + k - x > n) continue;
						upd(dp[i][j + 1][t | (1 << k)], dp[i - 1][j][s]);
					}
			}
		}
	}
	for (int i = 0; i <= n; ++ i)
		for (int s = 0, tmp; s < (1 << (x << 1) + 1); ++ s) {
			tmp = (i & 1) ? (MOD - dp[n][i][s]) : (dp[n][i][s]);
			upd(ans, (LL)tmp * fac[n - i] % MOD);
		}
	return printf("%d\n", ans), 0;
}
