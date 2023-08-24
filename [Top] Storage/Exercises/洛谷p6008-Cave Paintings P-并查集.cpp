#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e3 + 10;
const int MOD = 1e9 + 7;
const int dx[] = {0, 1, 0};
const int dy[] = {-1, 0, 1};
int n, m, ans = 1;
char g[N][N];
int fa[N * N], dp[N * N];
bool st[N * N];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline int hsh(int x, int y) { return (x - 1) * n + y; }

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x ^ y) fa[x] = y, dp[y] = (LL)dp[x] * dp[y] % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> g[i] + 1;
		for (int j = 1; j <= m; ++ j)
			if (g[i][j] - '#')
				fa[hsh(i, j)] = hsh(i, j), dp[hsh(i, j)] = 1;
	}	
	for (int i = n - 1; i > 1; -- i) {
		for (int j = 2; j < m; ++ j) {
			if (g[i][j] - '.') continue;
			for (int k = 0; k < 3; ++ k) 
				if (g[i + dx[k]][j + dy[k]] - '#') 
					merge(hsh(i, j), hsh(i + dx[k], j + dy[k]));
		}
		for (int j = 2; j < m; ++ j) {
			if (g[i][j] - '.') continue;
			int f = find(hsh(i, j));
			if (st[f]) continue;
			st[f] = true, dp[f] += 1;
		}
		for (int j = 2; j < m; ++ j) 
			if (g[i][j] - '#') st[find(hsh(i, j))] = false;
	}
	for (int i = n - 1; i > 1; -- i)
		for (int j = 2; j < m; ++ j)
			if (g[i][j] != '#' and hsh(i, j) == fa[hsh(i, j)]) 
				ans = (LL)ans * dp[hsh(i, j)] % MOD;
	return cout << ans << '\n', 0;
}
