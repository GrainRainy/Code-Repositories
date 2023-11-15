#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 30 + 5;
const int M = 1e2 + 10;
const int MOD = 998244353;
int n, m, k;
LL v[M][N], fac[N] = {1}, fav[N], f[M][N][N][N], ans;

LL qpow(LL a, int b) {
	LL res = 1;
	for (; b; a = (LL)a * a % MOD, b >>= 1)
		if (b & 1) res = (LL)res * a % MOD;
	return res;
}

int count(int x) {
	int res = 0;
	while (x) res += x & 1, x >>= 1;
	return res;
}

void upd(LL &x, LL y) { if ((x += y) >= MOD) x -= MOD; }
LL C(int n, int m) { return fac[n] * fav[m] % MOD * fav[n - m] % MOD; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i <= m; ++ i) cin >> v[i][1];
	for (int i = 0; i <= m; ++ i) {
		v[i][0] = 1;
		for (int j = 2; j <= n; ++ j) v[i][j] = v[i][j - 1] * v[i][1] % MOD;
	}
	for (int i = 1; i <= n; ++ i) fac[i] = fac[i - 1] * i % MOD;
	fav[n] = qpow(fac[n], MOD - 2);
	for (int i = n; i; -- i) fav[i - 1] = fav[i] * i % MOD;
	for (int i = 0; i <= n; ++ i) f[0][i][i & 1][i >> 1] = v[0][i] * C(n, i) % MOD;
	for (int i = 0; i < m; ++ i) 
		for (int j = 0; j <= n; ++ j) 
			for (int a = 0; a <= k; ++ a) 
				for (int b = 0; b <= n >> 1; ++ b) 
					for (int c = 0; c + j <= n; ++ c) 
						upd(f[i + 1][j + c][a + (b + c & 1)][b + c >> 1],
							f[i][j][a][b] * v[i + 1][c] % MOD * C(n - j, c) % MOD);
	for (int i = 0; i <= k; ++ i)
		for (int j = 0; j <= n >> 1; ++ j)
			if (i + count(j) <= k) upd(ans, f[m][n][i][j]);
	return cout << ans << '\n', 0;
}
