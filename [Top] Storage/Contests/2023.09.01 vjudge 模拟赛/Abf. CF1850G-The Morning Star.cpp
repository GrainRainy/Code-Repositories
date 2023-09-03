#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
int n, x[N], y[N];
LL ans = 0;

inline bool check(int i, int j) {
	if (x[i] == x[j] or y[i] == y[j]) return true;
	if (x[i] - x[j] == y[i] - y[j]) return true;
	if (x[i] - x[j] == -(y[i] - y[j])) return true;
	return false;
}

void solve() {
	cin >> n; ans = 0;
	for (int i = 1; i <= n; ++ i)
		cin >> x[i] >> y[i];
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j) {
			if (i == j) continue;
			if (check(i, j)) ans ++;
		}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
}
