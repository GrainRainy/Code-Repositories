#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e2 + 10;
const int MOD = 998244353;
LL n, f[N * N], ans = 1;

LL qpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= n; ++ i)
		for (int j = n * (n + 1) / 2; j >= i; -- j)
			f[j] = (f[j] + f[j - i]) % (MOD - 1);
	for (int i = 1; i <= n * (n + 1) / 2; ++ i)
		ans = ans * qpow(i, f[i]) % MOD;
	return cout << ans << '\n', 0;
}
