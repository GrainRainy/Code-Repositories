#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
int t, n, m, q, a[N], x;
LL ans, tmp;

int count(int x) {
	int cnt = 0;
	while (x) {
		cnt += x & 1;
		x >>= 1;
	}
	return cnt;
}

void solve() {
	cin >> n >> m >> q;
	for (int i = 1; i <= m; ++ i) cin >> a[i];
	while (q --) {
		cin >> x;
		ans = 0;
		for (int i = 1; i < (1 << n); ++ i) {
			if (!(count(i & x) & 1)) continue;
			tmp = 1;
			for (int j = 1; j <= m; ++ j) {
				tmp *= count(i & x) & count(i & a[j]) & 1;
				if (!tmp) break;
			}
			ans += tmp;
		}
		cout << ans << endl;	
	}
}

int main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t --) solve();
	return 0;
}
