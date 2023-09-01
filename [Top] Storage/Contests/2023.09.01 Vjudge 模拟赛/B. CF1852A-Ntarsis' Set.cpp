#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
int n, k, ary[N], mx, cnt, tmp;
LL nw;

void solve() {
	cin >> n >> k; k ++;
	tmp = mx = 0;
	for (int i = 1; i <= n; ++ i) {
		cin >> ary[i];
		mx = max(mx, ary[i]);
	}
	if (ary[1] != 1) return cout << 1 << '\n', void();
	if (n == 1) return cout << k << '\n', void();
	if (ary[2] - 1 > k) return cout << k << '\n', void();
	nw = ary[2] - 1, cnt = ary[2] - 1;
	while (cnt < k and nw < mx) {
		do {
			tmp = upper_bound(ary + 1, ary + n + 1, nw + tmp) - ary - 1;
		} while (upper_bound(ary + 1, ary + n + 1, nw + tmp) - ary - 1 != tmp);
		nw += tmp, cnt ++;
	}
	if (cnt == k) return cout << nw << '\n', void();
	else return cout << (LL)(k - cnt) * n + nw << '\n', void();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
