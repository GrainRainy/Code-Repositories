#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int L = 1e6 + 10;
const int MOD = 1e9 + 7;
int n, mx, a[N], f[L], stk[L], top, ans = 1;
map<int, int> mp;

int qpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = (LL)a * a % MOD)
		if (b & 1) res = (LL)res * a % MOD;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i], mx = max(mx, a[i]);
	for (int i = 2; i <= mx; ++ i) {
		if (!f[i]) stk[++ top] = i, f[i] = i;
		for (int j = 1; j <= top and stk[j] <= mx / i; ++ j) {
			f[i * stk[j]] = stk[j];
			if (!(i % stk[j])) break;
		}
	}
	for (int i = 1; i <= n; ++ i) {
		while (a[i] != 1) {
			int c = 0, p = f[a[i]];
			while (!(a[i] % p)) c ^= 1, a[i] /= p;
			if (c) mp[p] ++;
		}
	}
	for (auto t : mp) ans = (LL)qpow(t.first, min(t.second, n - t.second)) * ans % MOD;
	return cout << ans << '\n', 0;
}
