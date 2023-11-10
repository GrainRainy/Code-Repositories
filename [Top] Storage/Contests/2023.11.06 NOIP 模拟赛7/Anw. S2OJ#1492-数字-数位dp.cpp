#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 20;
const int M = 50;
const int MOD = 2520;
LL l, r;
int stk[N], stp, id[MOD + 10], itp;
LL f[N][MOD + 10][M];

LL dp(int pos, int sm, int cm, bool lim) {
	if (!pos) return sm % cm == 0;
	if (!lim and ~f[pos][sm][id[cm]]) return f[pos][sm][id[cm]];
	LL res = dp(pos - 1, sm * 10 % MOD, cm, lim and !stk[pos]);
	for (int i = 1; i <= (lim ? stk[pos] : 9); ++ i)
		res += dp(pos - 1, (sm * 10 + i) % MOD, cm * i / __gcd(cm, i), lim and i == stk[pos]);
	if (!lim) f[pos][sm][id[cm]] = res;
	return res;
}

LL sol(LL x) {
	stp = 0;
	while (x) stk[++ stp] = x % 10, x /= 10;
	return dp(stp, 0, 1, true);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for (int i = 1; i <= MOD / i; ++ i)
		if (!(MOD % i)) {
			id[i] = ++ itp;
			if (i != MOD / i) id[MOD / i] = ++ itp;
		}
	memset(f, -1, sizeof f);
	int t; cin >> t;
	while (t --) cin >> l >> r, cout << sol(r) - sol(l - 1) << '\n';
	return 0;
} 
