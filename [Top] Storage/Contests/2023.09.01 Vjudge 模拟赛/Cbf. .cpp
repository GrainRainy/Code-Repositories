#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
int n, k, a, b, ans;
int fac[N] = {1};

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

int qmul(int a, int b) {
	int res = 0;
	while (b) {
		if (b & 1) upd(res, a);
		upd(a, a);
		b >>= 1;
	}
	return res;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) fac[i] = (LL)fac[i - 1] * i % MOD;
	fac[n] = qpow(fac[n], MOD - 2);
	for (int i = n - 1; i; -- i) fac[i] = (LL)fac[i + 1] * (i + 1) % MOD;
	for (int i = 1; i <= n; ++ i) {
		a = b = 1;
		for (int j = n; j >= n - i + 1; -- j) a = qmul(a, j);
		a = (LL)a * fac[i] % MOD, b = qpow(i, k);
		upd(ans, qmul(a, b));
	}
	cout << ans << '\n';
	return 0;
}
