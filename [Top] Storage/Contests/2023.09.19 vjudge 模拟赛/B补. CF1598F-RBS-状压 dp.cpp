#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' <<x << '\n';
using namespace std;
const int N = 20 + 2;
int n, sm[N], mn[N], ans;
string s;
bool able[1 << N] = { true };
int ssm[1 << N], dp[1 << N];
unordered_map<int, int> c[N], pc[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1, val; i <= n; ++ i) {
		cin >> s, val = 0;
		for (auto t : s) {
			val += t == '(' ? 1 : -1;
			mn[i] = min(mn[i], val);
			if (!c[i][val]) pc[i][val] = c[i][val + 1];
			c[i][val] ++;
		}
		sm[i] = val;
	}
	for (int s = 0, ssm; s < 1 << n; ++ s) {
		if (!able[s]) continue;
		ssm = 0;
		for (int i = 1; i <= n; ++ i) if ((s >> i - 1) & 1) ssm += sm[i];
		for (int i = 1; i <= n; ++ i) {
			if ((s >> i - 1) & 1) continue;
			if (ssm + mn[i] >= 0) {
				dp[s | (1 << i - 1)] = max(dp[s | (1 << i - 1)], dp[s] + c[i][-ssm]);
				able[s | (1 << i - 1)] = true;
			} else ans = max(ans, dp[s] + pc[i][-ssm - 1]);
		}
	}
	for (int s = 0; s < 1 << n; ++ s) ans = max(ans, dp[s]);
	return cout << ans << '\n', 0;
}
