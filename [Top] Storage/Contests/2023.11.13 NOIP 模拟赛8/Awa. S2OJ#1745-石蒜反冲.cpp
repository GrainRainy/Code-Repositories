#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n'; 
using namespace std;
const int N = 1e4 + 10;
const int M = 3e3 + 10;
const int MOD = 993244353;
int n, f[2][M][20][2];
char s[N], a[10] = " sakana", b[15] = " chinanago";

void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> s + 1;
	f[0][n / 10 + 1][0][0] = f[0][n / 10 + 1][0][1] = 1;
//	for (int i = 1; i <= 8; ++ i) {
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n / 6; ++ j) {
			for (int k : {0, 1}) for (int len = 0; len < (k ? 9 : 6); ++ len) {
				if (s[i] == '?') {
					upd(f[i & 1][j][0][k], f[i & 1][j][k][len] * 25 % MOD);
					int dt = (len + 1 == (k ? 9 : 6)) ? (k ? -1 : 1) : 0;
					if (j + dt) upd(f[i & 1][j][len + 1][k], f[i - 1 & 1][j][len][k]);
//					if (i == 9 and j == 100 and len == 8 and k == 1)
//						debug(f[i][j + ((len + 1 == (k ? 9 : 6)) ? (k ? -1 : 1) : 0)][len + 1][k])
				} else {
					if (s[i] == (k ? b[len + 1] : a[len + 1])) {
						if (len + 1 == (k ? 9 : 6)) 
							upd(f[i & 1][j + (k ? -1 : 1)][len + 1][k], f[i - 1 & 1][j][len][k]);
						else upd(f[i & 1][j][len + 1][k], f[i - 1 & 1][j][len][k]);
					} else upd(f[i & 1][j][0][k], f[i - 1 & 1][j][len][k]);
				}
			}
		}
		if (i == 1) f[0][100][0][0] = f[0][100][0][1] = 0;
	}
//	debug(f[8][100][0][0])
	int res = 0;
	for (int i = 0; i <= 6; ++ i) upd(res, f[n & 1][100][i][0]);
	for (int i = 0; i <= 9; ++ i) upd(res, f[n & 1][100][i][1]);
	return cout << res << '\n', 0;
}
