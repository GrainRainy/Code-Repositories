#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e2 + 10;
const int MOD = 998244353;
LL n, ans = 1, c[10000];

int main() {
	cin >> n;
	for (LL s = 1; s < 1 << n; ++ s) {
		LL res = 0;
		for (int i = 1; i <= n; ++ i)
			if ((s >> i - 1) & 1) res += i;
		ans = ans * res % MOD;
		c[res] ++;
	}
	return cout << ans << '\n', 0;
}

