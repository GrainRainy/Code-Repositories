#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int LOG = 62;
int n, pos, id[N], cnt[2][N], dp[LOG][N];
LL a[N];

inline bool cmp(int x, int y) {	return (a[x] & (1ll << pos) - 1) < (a[y] & (1ll << pos) - 1); }


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) a[i] = a[n] - a[i], id[i] = i;
	memset(dp, 0x3f, sizeof dp); dp[0][0] = 0;
	for (; pos <= 60; ++ pos) {
		sort(id + 1, id + n + 1, cmp);
		for (int i = 1; i <= n; ++ i) {
			cnt[0][i] = cnt[0][i - 1] + !((a[id[i]] >> pos) & 1);
			cnt[1][i] = cnt[1][i - 1] + ((a[id[i]] >> pos) & 1);
		}
		for (int i = 0, cnta, cntb; i <= n; ++ i) {
			cnta = cnt[1][n - i] + cnt[0][n] - cnt[0][n - i];
			cntb = cnt[1][n] - cnt[1][n - i];
			dp[pos + 1][cntb] = min(dp[pos + 1][cntb], dp[pos][i] + cnta);
			cnta = cnt[0][n - i] + cnt[1][n] - cnt[1][n - i];
			cntb = n - cnt[0][n - i];
			dp[pos + 1][cntb] = min(dp[pos + 1][cntb], dp[pos][i] + cnta);
		}
	}
	return cout << dp[61][0] << '\n', 0;
}
