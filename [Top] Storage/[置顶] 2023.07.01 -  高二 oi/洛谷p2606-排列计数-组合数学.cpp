#include <bits/stdc++.h>
using std::min;
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
int n, MOD;
int f[N], fac[N], fav[N], lg[N];

int qpow(int a, int b = MOD - 2) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

int C(int n, int m) {
	if (n < m) return 0;
	return (LL)fac[n] * fav[n - m] % MOD * fav[m] % MOD;
}

int Lucas(int n, int m) {
	if (!m) return 1;
	return (LL)C(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD) % MOD;
}

int main() {
	scanf("%d%d", &n, &MOD);
	lg[0] = -1, fac[0] = f[1] = f[2] = 1, f[3] = 2;
	for (int i = 1; i <= n; ++ i) 
		fac[i] = (LL)fac[i - 1] * i % MOD, lg[i] = lg[i >> 1] + 1;
	fav[min(MOD - 1, n)] = qpow(fac[min(MOD - 1, n)]);
	for (int i = min(MOD - 1, n) - 1; i >= 0; -- i) 
		fav[i] = (LL)fav[i + 1] * (i + 1) % MOD;
	for (int i = 4, l = 1, r = 1; i <= n; ++ i) {
		if (i - (1 << lg[i]) + 1 <= (1 << lg[i] - 1)) l ++;
		else r ++;
		f[i] = (LL)Lucas(i - 1, l) * f[l] % MOD * f[r] % MOD;
	}
	return printf("%d\n", f[n]), 0;
}
