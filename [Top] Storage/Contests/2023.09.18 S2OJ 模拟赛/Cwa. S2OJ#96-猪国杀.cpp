#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e2 + 10;
const int M = 1e3 + 10;
const int MOD = 998244353;
LL n, m, l, f[N][M], invl, ans;

LL qpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

inline void upd(LL &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	cin >> n >> m >> l;
	f[0][0] = 1;
	invl = qpow(l, MOD - 2);
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j)
			for (int k = 1; k + j <= m; ++ k)
				f[i + 1][j + k] += invl * f[i][j] % MOD;
	}
	for (int i = 1; i <= n; ++ i) {
		LL res = 0;
		for (int j = 0; j <= m; ++ j)
			if (i == n or l - m + j > 0)
				upd(res, f[i][j] * invl % MOD * qpow(l - m + j, n - i) % MOD);
		upd(ans, res * i % MOD);
	}
	cout << ans << '\n';
}
