#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e3 + 10;
const int MOD = 1e9 + 7;
int n, k, f[N], ans;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

inline void upd(int &x, const int &y) { x += y; if (x >= MOD) x -= MOD; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	f[0] = 1;
	for (int i = 1; i <= k; ++ i) {
		for (int j = min(i, n); j; -- j)
			f[j] = ((LL)f[j - 1] * (n - j + 1) % MOD + (LL)f[j] * j) % MOD;
		if (i == 1) f[0] = 0;
	}
	for (int i = 1; i <= min(k, n); ++ i)
		upd(ans, (LL)f[i] * qpow(2, n - i) % MOD);
	return cout << ans << '\n', 0; 
}
