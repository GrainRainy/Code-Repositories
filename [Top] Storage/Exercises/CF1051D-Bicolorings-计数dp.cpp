#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int MOD = 998244353;
int n, k, f[N][N << 1][4];
int trans[4][4] = {
	0, 1, 1, 1,
	0, 0, 2, 0,
	0, 2, 0, 0,
	1, 1, 1, 0
};

void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int main() {
	cin >> n >> k;
	f[1][1][0] = f[1][2][1] = f[1][2][2] = f[1][1][3] = 1;
	for (int i = 2; i <= n; ++ i) 
		for (int j = 1; j <= k; ++ j)
			for (int a = 0; a < 4; ++ a)
				for (int b = 0; b < 4; ++ b) 
					if (j > trans[b][a]) upd(f[i][j][a], f[i - 1][j - trans[b][a]][b]);
	upd(f[n][k][0], f[n][k][1]), upd(f[n][k][0], f[n][k][2]), upd(f[n][k][0], f[n][k][3]);
	return cout << f[n][k][0] << '\n', 0;
}
