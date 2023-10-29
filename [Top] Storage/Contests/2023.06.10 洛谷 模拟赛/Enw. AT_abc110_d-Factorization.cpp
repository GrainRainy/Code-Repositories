#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int SQRTM = 4e4 + 10;
const int MOD = 1e9 + 7;

int n, m, mxtmp = 1, ans = 1;
int stk[SQRTM], top;
int fact[N + SQRTM], ifact[N + SQRTM];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

LL C(int n, int m) {
	return n < m ? 0 : (LL)fact[n] * ifact[m] % MOD * ifact[n - m] % MOD;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 2; i <= m / i; ++ i) {
		if (!(m % i)) {
			top ++;
			while (!(m % i)) stk[top] ++, m /= i;
			mxtmp = max(mxtmp, stk[top]);
		}
	}
	if (m != 1) stk[++ top] = 1;
	
	fact[0] = 1;
	for (int i = 1; i <= mxtmp + n; ++ i) fact[i] = (LL)fact[i - 1] * i % MOD;
	ifact[mxtmp + n] = qpow(fact[mxtmp + n], MOD - 2);
	for (int i = mxtmp + n - 1; ~i; -- i) ifact[i] = (LL)ifact[i + 1] * (i + 1) % MOD;
	
	for (int i = 1; i <= top; ++ i) 
		ans = (LL)ans * C(n + stk[i] - 1, stk[i]) % MOD;
	cout << ans << endl;
	return 0;
}
