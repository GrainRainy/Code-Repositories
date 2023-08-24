#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << endl;
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int MOD = 998244353;
int n, ca, cb, fac[N] = {1}, top;
char s[N];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

void solve() {
	ca = cb = 0;
	cin >> n >> s;
	s[n] = '0';
	for (int i = 0; i < n; ++ i) {
		if (s[i] - '0' and s[i + 1] - '0') ca ++, i ++;
		else if (s[i] - '0') cb ++;
	}
	while (top < n) fac[++ top] = (LL)fac[top - 1] * top % MOD;
	cout << (LL)fac[n - ca - cb] * qpow(fac[ca], MOD - 2) % MOD * qpow(fac[n - (ca << 1) - cb], MOD - 2) % MOD << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
