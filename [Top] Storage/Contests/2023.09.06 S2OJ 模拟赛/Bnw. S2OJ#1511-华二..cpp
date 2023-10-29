#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int MOD = 998244353;
int n, c[10], fac[N] = {1}, fav[N], ans = 1;

int qpow(int a, int b) {int res = 1; for (; b; b >>= 1, a = (LL)a * a % MOD) if (b & 1) res = (LL)res * a % MOD; return res; }
inline int C(int n, int m) { return (LL)fac[n] * fav[m] % MOD * fav[n - m] % MOD; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) fac[i] = (LL)fac[i - 1] * i % MOD;
	fav[n] = qpow(fac[n], MOD - 2);
	for (int i = n; ~i; -- i) fav[i - 1] = (LL)fav[i] * i % MOD;
	for (int i = 1, tmp; i <= n; ++ i) {
		cin >> tmp;
		c[tmp] ++;
		if (tmp == 6) {
			ans = (LL)ans * C(c[2] + c[3] + c[4] + c[8] + c[9], c[3] + c[9]) % MOD;
			c[2] = c[3] = c[4] = c[8] = c[9] = 0;
		}
	}
	ans = (LL)ans * C(c[2] + c[3] + c[4] + c[8] + c[9], c[3] + c[9]) % MOD;
	ans = (LL)ans * fac[n] % MOD * fav[c[1]] % MOD * fav[c[5]] % MOD * fav[c[7]] % MOD * fav[n - c[1] - c[5] - c[7]] % MOD;
	return cout << ans << '\n', 0;
}
