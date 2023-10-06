#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e2 + 10;
const int MOD = 998244353;
int n, x, f[N][N];
int fac[N] = {1}, fav[N];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

inline void upd(int &x, int y) { x += y; if (x >= MOD) x -= MOD; }
inline int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
inline int C(int n, int m) { return (LL)fac[n] * fav[m] % MOD * fav[n - m] % MOD; }

int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; ++ i) fac[i] = (LL)fac[i - 1] * i % MOD;
	fav[n] = qpow(fac[n], MOD - 2);
	for (int i = n - 1; ~i; -- i) fav[i] = (LL)fav[i + 1] * (i + 1) % MOD;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= i - 1; ++ j) f[i][j] = add(qpow(j, i), MOD - qpow(j - 1, i));
		for (int j = i; j <= x; ++ j) 
			for (int k = 1; k <= i; ++ k)
				upd(f[i][j], (LL)C(i, k) * f[k][j - i + 1] % MOD * qpow(i - 1, i - k) % MOD);
	}
	int res = 0;
	for (int i = 1; i <= x; ++ i) upd(res, f[n][i]);
	return cout << res << '\n', 0;
}
