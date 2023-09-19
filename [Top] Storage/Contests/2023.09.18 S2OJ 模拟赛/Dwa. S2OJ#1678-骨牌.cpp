#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, v[2][N];
vector<int> pos[2][N];
int stk[N], ans[N];
bool st[N];

void dfs(int u, bool ab) {
	if (u == n) {
		bool f = false;
		for (int i = 1; i <= n; ++ i)
			if (stk[i] < ans[i]) { f = true; break; }
		if (f) for (int i = 1; i <= n; ++ i) ans[i] = stk[i];
		return;
	}
	for (auto t : pos[ab][v[ab][stk[u]]]) {
		if (st[t]) continue;
		stk[u + 1] = t, st[t] = true;
		dfs(u + 1, ab ^ 1);
		stk[u + 1] = 0, st[t] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		ans[i] = 0x3f3f3f3f;
		cin >> v[0][i] >> v[1][i];
		pos[0][0].push_back(i), pos[1][0].push_back(i);
		pos[0][v[0][i]].push_back(i), pos[1][v[1][i]].push_back(i);
	}
	dfs(0, 0);
	dfs(0, 1);
	if (ans[1] == 0x3f3f3f3f) return puts("No") & 0;
	cout << "Yes\n";
	for (int i = 1; i <= n; ++ i) cout << ans[i] << ' ';
	return cout << endl, 0;
}
