#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 3e5 + 10;
const int MOD = 998244353;
int n, a, b, fac[N], res;
LL k;

int qpow(int a, int b = MOD - 2) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

inline int C(int n, int m) {
	if (m > n or n > ::n) return 0;
	return (LL)fac[n] * qpow(fac[m]) % MOD * qpow(fac[n - m]) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> a >> b >> k;
	fac[0] = 1;
	for (int i = 1; i <= n; ++ i) fac[i] = (LL)fac[i - 1] * i % MOD;
	for (int i = 0; i <= n and (LL)a * i <= k; ++ i) {
		if (!((k - (LL)a * i) % b))
			res = (res + (LL)C(n, i) * C(n, (k - (LL)a * i) / b) % MOD) % MOD;
	}
	cout << res << endl;
}
