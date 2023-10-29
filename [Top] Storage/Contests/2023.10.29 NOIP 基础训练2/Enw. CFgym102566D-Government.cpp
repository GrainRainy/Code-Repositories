#include <bits/stdc++.h>
using namespace std;
const int N = 30 + 5;
int n, m, a[N][N][2], b[N], ans;
map<vector<int>, int> mp;

int ct(int s) {
	int res = 0;
	for (int i = n; ~i; -- i)
		res += (s >> i) & 1;
	return res;
}

void solve() {
	cin >> n >> m, mp.clear(), ans = 0x3f3f3f3f;
	vector<int> res(m + 1), tgt(m + 1);
	for (int i = 1; i <= m; ++ i) cin >> b[i];
	for (int i = 1; i <= n; ++ i) 
		for (int j = 1; j <= m; ++ j)
			cin >> a[i][j][0] >> a[i][j][1];
	for (int s = 0; s < 1 << (n >> 1); ++ s) {
		for (int j = 1; j <= m; ++ j) res[j] = 0;
		for (int i = 1; i <= n >> 1; ++ i) 
			for (int j = 1; j <= m; ++ j)
				res[j] += a[i][j][(s >> i - 1) & 1];
		if (mp.find(res) == mp.end()) mp[res] = ct(s);
		else mp[res] = min(ct(s), mp[res]);
	}
	for (int s = 0; s < 1 << (n - (n >> 1)); ++ s) {
		for (int j = 1; j <= m; ++ j) res[j] = 0;
		for (int i = 1; i <= (n - (n >> 1)); ++ i)
			for (int j = 1; j <= m; ++ j)
				res[j] += a[i + (n >> 1)][j][(s >> i - 1) & 1];
		for (int i = 1; i <= m; ++ i) tgt[i] = b[i] - res[i];
		ans = min(ans, ct(s) + (mp.find(tgt) == mp.end() ? 0x3f3f3f3f : mp[tgt]));
	}
	if (ans == 0x3f3f3f3f) return cout << "impossible\n", void();
	return cout << ans << '\n', void();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
