#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, t, ans[N][N];
set<pair<int, int>> st;
bool usd[N][N];

namespace sub0 {
	void solve() {
		for (int i = 1; i <= n; ++ i, cout << '\n')
			for (int j = 1; j <= i; ++ j)
				cout << i << ' ';
	}
}

void dfs(int x, int y) {
	if (y > x) y = 1, x ++;
	if (x == n + 1) {
		for (int i = 1; i <= n; ++ i, cout << '\n')
			for (int j = 1; j <= i; ++ j)
				cout << ans[i][j] << ' ';
		exit(0);
	}
	for (int i = 1; i <= n; ++ i)
		if ((t != 2 or !usd[x][i]) and st.find({ans[x][y - 1], i}) == st.end()) {
			ans[x][y] = i, usd[x][i] = true;
			st.insert({ans[x][y - 1], ans[x][y]});
			st.insert({ans[x][y], ans[x][y - 1]});
			dfs(x, y + 1);
			st.erase({ans[x][y - 1], ans[x][y]});
			st.erase({ans[x][y], ans[x][y - 1]});
			ans[x][y] = 0, usd[x][i] = false;
		}
}

int main() {
	freopen("woof.in", "r", stdin);
	freopen("woof.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> t;
	if (!t) return sub0::solve(), 0;
	return dfs(1, 1), 0;
}
