#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int t, n, m, k;
int g[N][N];
vector<int> a;
map<vector<int>, bool> mp;

void dfs(int x, int y) {
	if (x == n and y == m + 1) {
		a.clear(), a.push_back(0);
		for (int i = 1; i <= n; ++ i) {
			a.push_back(0);
			for (int j = 1; j <= m; ++ j) 
				a[i] = max(a[i], g[i][j]);
		}
		for (int j = 1; j <= m; ++ j) {
			a.push_back(0);
			for (int i = 1; i <= n; ++ i)
				a[j + n] = max(a[j + n], g[i][j]);
		}
		mp[a] = true;
		return;
	} else if (y == m + 1) x ++, y = 1;
	for (int i = 1; i <= k; ++ i) {
		g[x][y] = i;
		dfs(x, y + 1);
	}
}

void solve() {
	cin >> n >> m >> k;
	mp.clear();
	dfs(1, 1);
	cout << mp.size() << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t --) solve();
	return 0;
}
