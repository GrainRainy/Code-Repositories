#include <bits/stdc++.h>
using namespace std;
int n, g[10][10], cntx[10][5], cnty[10][5];
char r[10], c[10];

void dfs(int x, int y) {
	if (x == n and y == n + 1) {
		for (int i = 1; i <= n; ++ i) {
			if (cntx[i][1] != 1 or cntx[i][2] != 1 or cntx[i][3] != 1) return;
			if (cnty[i][1] != 1 or cnty[i][2] != 1 or cntx[i][3] != 1) return;
		}
		for (int i = 1, j; i <= n; ++ i) {
			j = 1;
			while (!g[i][j]) j ++;
			if (g[i][j] - 1 + 'A' != r[i]) return;
		}
		for (int j = 1, i; j <= n; ++ j) {
			i = 1;
			while (!g[i][j]) i ++;
			if (g[i][j] - 1 + 'A' != c[j]) return;
		}
		cout << "Yes\n";
		for (int i = 1; i <= n; ++ i, cout << '\n')
			for (int j = 1; j <= n; ++ j)
				cout << (!g[i][j] ? '.' : (char)('A' + g[i][j] - 1));
		exit(0);
	}
	if (y == n + 1) x ++, y = 1;
	for (int i = 0; i <= 3; ++ i) {
		if (i and (cntx[x][i] or cnty[y][i])) continue;
		if (x == 1 and i and c[y] != (char)('A' + i - 1)) continue;
		if (y == 1 and i and r[x] != (char)('A' + i - 1)) continue;
		g[x][y] = i, cntx[x][i] ++, cnty[y][i] ++;
		dfs(x, y + 1);
		g[x][y] = 0, cntx[x][i] --, cnty[y][i] --;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> r + 1 >> c + 1;
	dfs(1, 1);
	return puts("No") & 0;
}
