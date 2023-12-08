#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
int n, m, sm[N][30];
string s;
bool ans[N];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> s;
		for (auto t : s) sm[i][t - 'a'] ++;
		for (int j = 1; j <= 26; ++ j)
			sm[i][j] += sm[i][j - 1];
	}
	for (int i = 1; i <= n; ++ i) {
		ans[i] = true;
		int p = 0;
		while (!sm[i][p]) p ++;
		for (int j = 1; j <= n; ++ j) {
			if (i == j) continue;
			if (!(sm[j][26] - sm[j][p])) {
				ans[i] = false;
				break;
			}
		}
	}
	for (int i = 1; i <= n; ++ i) cout << ans[i];
	return cout << '\n', 0;
}
