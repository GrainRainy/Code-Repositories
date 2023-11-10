#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e5 + 10;
LL l, r, ans;

bool ck(LL a) {
	LL tmp = a;
	for (; a; a /= 10)
		if (a % 10 and tmp % (a % 10)) return false;
	return true;
}

void solve() {
	cin >> l >> r, ans = 0;
	for (LL i = l; i <= r; ++ i)
		ans += ck(i);
	return cout << ans << '\n', void();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
