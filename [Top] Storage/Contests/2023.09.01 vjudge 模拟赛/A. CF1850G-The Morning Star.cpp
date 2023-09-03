#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int n; LL ans;
void solve() {
	map<int, int> x, y;
	map<LL, int> ax, bx;
	ans = 0;
	cin >> n;
	for (int i = 1, xx, yy; i <= n; ++ i) {
		cin >> xx >> yy;
		x[xx] ++, y[yy] ++;
		ax[yy - xx] ++, bx[yy + xx] ++;
	}
	for (auto t : x) ans += (LL)(t.second) * (t.second - 1);
	for (auto t : y) ans += (LL)(t.second) * (t.second - 1);
	for (auto t : ax) ans += (LL)(t.second) * (t.second - 1);
	for (auto t : bx) ans += (LL)(t.second) * (t.second - 1);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
