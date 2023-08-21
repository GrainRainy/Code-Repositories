#include <bits/stdc++.h>
using namespace std;
const int N = 35 + 5;
int n, m, ary[N], a[2][1 << N / 2];

void dfs(int u, int tar, int res, bool type) {
	if (u == tar + 1) return a[type][++ a[type][0]] = res, void(); 
	dfs(u + 1, tar, res, type);
	dfs(u + 1, tar, (res + ary[u]) % m, type);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> ary[i];
	if (n == 1) return cout << ary[1] % m << endl, 0;
	dfs(1, n >> 1, 0, 0), dfs((n >> 1) + 1, n, 0, 1);
	sort(a[0] + 1, a[0] + a[0][0] + 1);
	sort(a[1] + 1, a[1] + a[1][0] + 1);
	int ans = (a[0][a[0][0]] + a[1][a[1][0]]) % m;
	for (int i = 1, r = a[1][0]; i <= a[0][0]; ++ i) {
		while (r > 1 and a[0][i] + a[1][r] >= m) r --;
		ans = max(ans, (a[0][i] + a[1][r]) % m);
	}
	return cout << ans << endl, 0;
}
