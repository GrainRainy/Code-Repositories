#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int MOD = 998244353;
int m, n, x, y, fac[N << 1] = {1}, fav[N << 1];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int C(int n, int m) { return (LL)fac[n] * fav[m] % MOD * fav[n - m] % MOD; }
int main() {
	cin >> m >> n >> x >> y;
	for (int i = 1; i <= n + m; ++ i) fac[i] = (LL)fac[i - 1] * i % MOD;
	fav[n + m] = qpow(fac[n + m], MOD - 2);
	for (int i = n + m - 1; ~i; -- i) fav[i] = (LL)fav[i + 1] * (i + 1) % MOD;
	if (x < n and y > n) {
		int res = 0;
		for (int i = 1; i <= m; ++ i) 
			upd(res, (LL)C(x + i - 2, x - 1) * C(n - x + m - i, n - x) % MOD 
					   * C(y - n - 1 + m - i, m - i) % MOD * C(n * 2 - y + i - 1, i - 1) % MOD);
		cout << res << '\n';
	} else cout << (LL)C(n + m - 1, n) * C(n - y + x + m - 1, m - 1) % MOD << '\n';
	return 0;
}
