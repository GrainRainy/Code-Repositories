#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int n, m, cc[N][30], cr[N][30], jg, ans;
char g[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> g[i] + 1;
		for (int j = 1; j <= m; ++ j)
			cc[j][g[i][j] - 'a'] ++, cr[i][g[i][j] - 'a'] ++;
	}
	vector<int> delc, delr;
	while (true) {
		delc.clear(); delr.clear();
		for (int i = 1; i <= n; ++ i) {
			if (cr[i][26]) continue;
			jg = 0;
			for (int j = 0; j < 26; ++ j) {
				if (jg and cr[i][j]) { jg = 0; break; }
				else if (cr[i][j]) jg = cr[i][j];
			}
			if (jg > 1) cr[i][26] = 1, delr.push_back(i);
		}
		for (int i = 1; i <= m; ++ i) {
			if (cc[i][26]) continue;
			jg = 0;
			for (int j = 0; j < 26; ++ j) {
				if (jg and cc[i][j]) { jg = 0; break; }
				else if (cc[i][j]) jg = cc[i][j];
			}
			if (jg > 1) cc[i][26] = 1, delc.push_back(i);
		}
		if (!delc.size() and !delr.size()) break;
		for (auto t : delr) 
			for (int i = 1; i <= m; ++ i)
				if (g[t][i] != '.') ans ++, cc[i][g[t][i] - 'a'] --, g[t][i] = '.';
		for (auto t : delc) 
			for (int i = 1; i <= n; ++ i)
				if (g[i][t] != '.') ans ++, cr[i][g[i][t] - 'a'] --, g[i][t] = '.';
	}
	return cout << n * m - ans << '\n', 0;
}
