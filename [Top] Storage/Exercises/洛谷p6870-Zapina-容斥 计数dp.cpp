#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 4e2 + 10;
const int MOD = 1e9 + 7;
int n, fac[N] = {1}, fav[N], f[N][N];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

inline void upd(int &x, int y) { if (y < 0) y += MOD; x += y; if (x >= MOD) x -= MOD; }
int C(int n, int m) { return (LL)fac[n] * fav[m] % MOD * fav[n - m] % MOD; }
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++ i) fac[i] = (LL)fac[i - 1] * i % MOD;
	fav[n] = qpow(fac[n], MOD - 2);
	for (int i = n - 1; ~i; -- i) fav[i] = (LL)fav[i + 1] * (i + 1) % MOD;
	f[0][0] = 1;
	for (int i = 1; i <= n; ++ i)
		for (int j = 0; j <= n; ++ j)
			for (int k = 0; k <= j; ++ k)
				if (j - k != i) upd(f[i][j], (LL)C(n - k, j - k) * f[i - 1][k] % MOD);
	cout << (qpow(n, n) - f[n][n] + MOD) % MOD << '\n';
	return 0;
}
