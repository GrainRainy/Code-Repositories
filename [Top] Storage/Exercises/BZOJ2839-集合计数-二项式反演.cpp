#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
const int MOD = 1000000007;
int n, k;
int pw2[N], fac[N], inv[N], fav[N], ans;

inline int C(int n, int m) {
	return (LL)fac[n] * fav[n - m] % MOD * fav[m] % MOD;
}

int main() {
	scanf("%d%d", &n, &k);
	fac[0] = fac[1] = fav[0] = fav[1] = pw2[0] = inv[1] = 1, pw2[0] = 2, pw2[1] = 4;
	for (int i = 2; i <= n; ++ i) {
		fac[i] = (LL)fac[i - 1] * i % MOD;
		inv[i] = (LL)(MOD - MOD / i) * inv[MOD % i] % MOD;
		pw2[i] = (LL)pw2[i - 1] * pw2[i - 1] % MOD;
		fav[i] = (LL)fav[i - 1] * inv[i] % MOD;
	}
	for (int i = k; i <= n; ++ i) {
		if (!((i & 1) ^ (k & 1))) ans = (ans + (LL)C(i, k) * C(n, i) % MOD * (pw2[n - i] - 1 + MOD) % MOD) % MOD;
		else ans = ((ans - (LL)C(i, k) * C(n, i) % MOD * (pw2[n - i] - 1 + MOD)) % MOD + MOD) % MOD;
	}
	return printf("%d\n", ans), 0;
}
