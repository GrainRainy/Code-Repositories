#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int t, n, m, ans;
string s;
set<int> st[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t --) {
		cin >> n >> m; ans = 0;
		for (int i = 1; i <= n; ++ i) {
			cin >> s;
			for (int j = 1; j <= m; ++ j)
				if (s[j - 1] == '1') st[i + j].insert(i);
		}
		for (int i = 1, pos; i <= n + m; ++ i) {
			if (!st[i + 1].size()) continue;
			pos = i, ans ++;
			for (int j = 1; j <= n; ++ j) {
				st[j + pos].erase(j);
				st[j + pos].size() and *st[j + pos].rbegin() > j ? pos -- : pos ++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
