#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 30 + 5;
const int M = 20 + 2;
const int MOD = 998244353;
int n, m, k, v[M];
LL f[N][1 << M], ans;

int count(int x) {
	int res = 0;
	for (; x; x >>= 1) res += x & 1;
	return res;
}

void upd(LL &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i <= m; ++ i) cin >> v[i];
	f[0][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		for (int s = i; s <= i * (1 << m); ++ s) {
			for (int j = 0; j <= m and 1 << j <= s; ++ j)
				upd(f[i][s], f[i - 1][s - (1 << j)] * v[j] % MOD);
		}
	}
	for (int s = n; s <= n * (1 << m); ++ s)
		if (count(s) <= k) upd(ans, f[n][s]);
	return cout << ans << '\n', 0;
}
