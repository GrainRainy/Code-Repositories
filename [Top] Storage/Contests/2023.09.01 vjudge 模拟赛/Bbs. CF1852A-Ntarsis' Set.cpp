#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
int n, a[N], k, cnt;
LL nw;

void solve() {
	cin >> n >> k; nw = 1, cnt = 0;
	for (int i = 0; i < n; ++ i) cin >> a[i];
	while (k --) {
		nw += cnt;
		while (cnt < n and a[cnt] <= nw) cnt ++, nw ++;
	}
	cout << nw << '\n';
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
