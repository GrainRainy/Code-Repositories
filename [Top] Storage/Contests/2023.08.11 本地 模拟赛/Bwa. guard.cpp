#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int N = 1e3 + 10;
int n, k, top, mn = 0x3f3f3f3f;
LL dp[N][N];
struct Node {
	int x, y;
	bool operator < (const Node &t) const {
		if (x ^ t.x) return x < t.x;
		return y > t.y;
	}
}d[N], nd[N];
LL ans = 0x3f3f3f3f3f3f3f3f;

int main() {
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) {
		cin >> d[i].x >> d[i].y;
		mn = min(mn, d[i].x + d[i].y);
	}
	sort(d + 1, d + n + 1);	
	for (int i = 1; i <= n; ++ i)
		if (d[i].y > d[i + 1].y) nd[++ top] = d[i];
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= top; ++ i) {
		dp[i][1] = 2 * nd[i].x + 2 * nd[i].y;
		for (int j = 2; j <= i and j <= k; ++ j) {
			for (int a = 0; a < i; ++ a) {
				dp[i][j] = min(dp[i][j], dp[a][j - 1] + 2 * nd[a + 1].y + 2 * nd[i].x);
			}
		}
	}
	for (int i = 1; i <= k; ++ i)
		ans = min(ans, dp[top][i] + (k - i) * mn);
	cout << ans << endl;
	return 0;
}
