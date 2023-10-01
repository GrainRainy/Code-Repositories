#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e3 + 10;
const int MOD = 1e9 + 7;
int n, invn, nw = 1, m, v, a[N], f[N][N], ans;

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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> v;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	invn = qpow(n, MOD - 2), nw = f[0][0] = 1;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j <= min(m, i); ++ j) {
			upd(f[i + 1][j], (LL)f[i][j] * a[i + 1] % MOD);
			upd(f[i + 1][j], (LL)f[i][j] * j % MOD * v % MOD);
			upd(f[i + 1][j + 1], (LL)f[i][j] * (i + 1) % MOD * v % MOD * (m - j) % MOD);
		}
	}
	for (int i = 0; i <= min(n, m); ++ i)
		upd(ans, (LL)f[n][i] * nw % MOD), nw = (LL)nw * invn % MOD;
	return cout << ans << '\n', 0;
}
