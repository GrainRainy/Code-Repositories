#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
int n, k, pw[N] = {1}, fac[N] = {1}, fav[N], ans;

int qpow(int a, int b) {
	int res = 1;
	for (; b; a = (LL)a * a % MOD, b >>= 1)
		if (b & 1) res = (LL)res * a % MOD;
	return res;
}

void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int C(int n, int m) { return (LL)fac[n] * fav[m] % MOD * fav[n - m] % MOD; }
int main() {
	cin >> n >> k;
	if (!k) return cout << qpow(3, n) << '\n', 0;
	for (int i = 1; i <= n; ++ i) {
		pw[i] = 1ll * pw[i - 1] * 3 % MOD;
		fac[i] = 1ll * fac[i - 1] * i % MOD;
	}
	fav[n] = qpow(fac[n], MOD - 2);
	for (int i = n; i; -- i) fav[i - 1] = (LL)fav[i] * i % MOD;
	for (int i = 1, r; i <= k; ++ i) {
		r = n - k - i + 1;
		if (r < 0) break;
		upd(ans, (LL)pw[n - (i << 1) + 1] * C(r + i - 1, i - 1) % MOD * C(k - 1, i - 1) % MOD);
		if (r) upd(ans, (LL)pw[n - (i << 1)] * C(r - 1 + i, i) % MOD * C(k - 1, i - 1) % MOD);
	}
	return cout << ans << '\n', 0;
}
