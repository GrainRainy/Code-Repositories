#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e2 + 10;
const int MOD = 998244353;
int n, m, fac[N << 1] = {1}, fav[N << 1], dp[N << 1][N << 1];
bool w[N << 1][N << 1];

int qpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = (LL)a * a % MOD)
		if (b & 1) res = (LL)res * a % MOD;
	return res;
}

int C(int n, int m) { return (LL)fac[n] * fav[m] % MOD * fav[n - m] % MOD; }
void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= (n << 1) + 1; ++ i) 
		fac[i] = (LL)fac[i - 1] * i % MOD, dp[i][i - 1] = 1;
	fav[n << 1] = qpow(fac[n << 1], MOD - 2);
	for (int i = n << 1; i; -- i) fav[i - 1] = (LL)fav[i] * i % MOD;
	for (int i = 1, l, r; i <= m; ++ i)
		cin >> l >> r, w[l][r] = w[r][l] = true;
	for (int len = 2; len <= n << 1; ++ len)
		for (int l = 1, r = len; r <= n << 1; l ++, r ++)
			for (int k = l + 1; k <= r; k += 2)
				if (w[l][k]) upd(dp[l][r], (LL)dp[l + 1][k - 1] * dp[k + 1][r] % MOD
											 * C(r - l + 1 >> 1, k - l + 1 >> 1) % MOD);
	return cout << dp[1][n << 1] << '\n', 0;
}
