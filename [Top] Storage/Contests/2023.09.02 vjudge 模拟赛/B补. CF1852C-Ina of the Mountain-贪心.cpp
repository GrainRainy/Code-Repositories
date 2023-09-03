#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int n, k, a[2];
LL ans;

void solve() {
	cin >> n >> k; a[0] = a[1] = ans = 0;
	priority_queue<LL, vector<LL>, greater<LL>> q;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i & 1];
		if (a[i & 1] == k) a[i & 1] = 0;
		if (a[0] == a[1]) continue;
		else if (a[i - 1 & 1] > a[i & 1]) q.push(a[i & 1] + k - a[i - 1 & 1]);
		else {
			q.push(a[i & 1] - a[i - 1 & 1]);
			ans += q.top(); q.pop();
		}
	}
	return cout << ans << '\n', void();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
