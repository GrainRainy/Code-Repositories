#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL n, ans = 1;

LL qpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	} 
	return res;
}

int main() {
	cin >> n;
	LL tmp = n;
	for (LL i = 2, cnt; i <= n / i; ++ i) {
		if (!(n % i)) {
			cnt = 0;
			while (!(n % i)) n /= i, cnt ++;
			ans *= qpow(i, (cnt + 1) / 2);
		}
	}
	if (n != 1) ans *= n;
	if (ans % tmp) cout << ans << '\n';
	else cout << -1 << '\n';
	return 0;
}
