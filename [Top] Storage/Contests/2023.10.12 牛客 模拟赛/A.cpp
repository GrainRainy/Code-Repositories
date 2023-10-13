#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
using namespace std;
const int N = 1e2 + 10;
int t, n, m;
vector<vector<int>> a(N);

bool cmp(vector<int> a, vector<int> b) {
	for (int i = 0; i < m; ++ i)
		if (a[i] != b[i]) return a[i] < b[i];
	return false;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++ i) a[i].clear(); 
	for (int i = 0; i < n; ++ i)
		for (int j = 0, tmp; j < m; ++ j)
			cin >> tmp, a[i].emplace_back(tmp);
	sort(a.begin(), a.begin() + n, cmp);
	for (int j = 0, mxp; j < m; ++ j) {
		mxp = 1;
		for (int i = 0; i < n; ++ i) {
			if (a[i][j] < mxp) return cout << "NO\n", void();
			else mxp = a[i][j];
		}
	}
	return cout << "YES\n", void();
}

int main() {
	freopen("sample.in", "r", stdin);
	freopen("sample.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t --) solve();
	return 0;
}
