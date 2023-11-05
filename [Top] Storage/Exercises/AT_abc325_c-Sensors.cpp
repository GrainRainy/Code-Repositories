#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, ans;
char g[N][N];
bool st[N][N];

void dfs(int x, int y) {
	st[x][y] = true;
	for (int i = 0, nx, ny; i < 8; ++ i) {
		nx = x + dx[i], ny = y + dy[i];
		if (nx and nx <= n and ny and ny <= m and g[nx][ny] == '#' and !st[nx][ny])
			dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> g[i] + 1;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			if (g[i][j] == '#' and !st[i][j]) ans ++, dfs(i, j);
	return cout << ans << '\n', 0;
}
