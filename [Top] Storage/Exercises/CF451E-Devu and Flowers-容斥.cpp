#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 20 + 5;
const int MOD = 1e9 + 7;
int n, cnt, ans;
LL f[N], s, tot;
LL fav[N] = {1};

inline void upd(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

inline int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

inline int C(int n, int m) {
	if (n < m) return 0;
	LL res = 1;
	for (int i = 0; i < m; ++ i) res = res * (n - i) % MOD;
	return res * fav[m] % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; ++ i)
		cin >> f[i], fav[i] = (LL)fav[i - 1] * i % MOD;
	fav[n] = qpow(fav[n], MOD - 2);
	for (int i = n - 1; ~i; -- i) fav[i] = fav[i + 1] * (i + 1) % MOD;
	for (int i = 0; i < 1 << n; ++ i) {
		cnt = tot = 0;
		for (int j = 1; j <= n; ++ j)
			if ((i >> j - 1) & 1) cnt ++, tot += f[j] + 1;
		upd(ans, (cnt & 1 ? -1 : 1) * C((s - tot + n - 1) % MOD, n - 1));
	}
	return cout << ans << '\n', 0;
}
