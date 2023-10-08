#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 250 + 10;
const int MOD = 998244353;
int n, k, dp[N][N], ps[N][N], fac[N] = {1}, fav[N];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

int C(int n, int m) { return (LL)fac[n] * fav[m] % MOD * fav[n - m] % MOD; }
inline void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) fac[i] = (LL)fac[i - 1] * i % MOD;
	fav[n] = qpow(fac[n], MOD - 2);
	for (int i = n - 1; ~i; -- i) fav[i] = (LL)fav[i + 1] * (i + 1) % MOD;
	dp[1][0] = 1;
	for (int i = 0; i <= k; ++ i) ps[1][i] = 1;
	for (int i = 2; i <= n; ++ i) 
		for (int j = 1; j <= k; ++ j) {
			for (int a = 1; a < i; ++ a)
				upd(dp[i][j], (LL)ps[a][j - 1] * C(n - a, i - a) % MOD
							* qpow(k - j + 1, (LL)(i + a - 3) * (i - a) / 2 % MOD) % MOD);
			upd(ps[i][j], ps[i][j - 1]), upd(ps[i][j], dp[i][j]);
		}
	int res = 0;
	for (int i = 0; i <= k; ++ i) upd(res, dp[n][i]);
	return cout << res << '\n', 0;
}
