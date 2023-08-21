#include <bits/stdc++.h>
using namespace std;
const int N = 20 + 5;
int n, a[N], tot, ans[1 << 21], ot;
vector<int> g[1 << 21];
map<int, int> mp;

void dfs(int u, int tar, int delta, int state, bool type) {
	if (u == tar + 1) {
		if (type) {
			int tmp = mp[delta];
			if (tmp) for (auto t : g[tmp]) ans[t | state] = 1;
		} else {
			if (!mp[delta]) mp[delta] = ++ tot;
			g[mp[delta]].push_back(state);
		}
		return;
	}
	dfs(u + 1, tar, delta, state, type);
	dfs(u + 1, tar, delta + a[u], state | (1 << u - 1), type);
	dfs(u + 1, tar, delta - a[u], state | (1 << u - 1), type);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	dfs(1, n >> 1, 0, 0, 0), dfs((n >> 1) + 1, n, 0, 0, 1);
	for (int i = 1; i < 1 << n; ++ i) ot += ans[i];
	return cout << ot << endl, 0;
} 
