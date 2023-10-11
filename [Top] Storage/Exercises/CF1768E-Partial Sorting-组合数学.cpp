#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
int n, mod, fac[N * 3] = {1}, fav[N * 3], sm, ans;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % mod;
		a = (LL)a * a % mod;
		b >>= 1;
	}
	return res;
}

int C(int n, int m) { return (LL)fac[n] * fav[m] % mod * fav[n - m] % mod; }
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
void upd(int &a, int b) { if ((a += b) >= mod) a -= mod; }

int main() {
	cin >> n >> mod;
	for (int i = 1; i <= n * 3; ++ i) fac[i] = (LL)fac[i - 1] * i % mod;
	fav[n * 3] = qpow(fac[n * 3], mod - 2);
	for (int i = n * 3; i; -- i) fav[i - 1] = (LL)fav[i] * i % mod;
	upd(ans, add(fac[n << 1], fac[n << 1])), upd(ans, mod - fac[n] - 1);
	if ((sm = (LL)C(n << 1, n) * fac[n] % mod * fac[n << 1] % mod << 1) >= mod) sm -= mod;
	for (int i = 0; i <= n; ++ i)
		upd(sm, mod - (LL)C(n, i) * C(n, i) % mod * C((n << 1) - i, n) % mod * fac[n] % mod * fac[n] % mod * fac[n] % mod);
	upd(ans, add(add(sm, mod - ans - 1), add(sm, mod - ans - 1))), upd(ans, 3ll * add(fac[n * 3], mod - sm) % mod);
	return cout << ans << '\n', 0;
}
