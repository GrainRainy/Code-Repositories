#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
int n, m, dp[N][N];
bool dx[N][N], dy[N][N];
char a[N], b[N];

void print(int x, int y) {
	if (!x or !y) return;
	print(x - dx[x][y], y - dy[x][y]);
	if (a[x] == b[y]) cout << a[x];
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> a + 1 >> b + 1;
	n = strlen(a + 1), m = strlen(b + 1);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j) {
			if (a[i] == b[j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				dx[i][j] = dy[i][j] = true;
			} else if (dp[i - 1][j] > dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j], dx[i][j] = true;
			} else {
				dp[i][j] = dp[i][j - 1], dy[i][j] = true;
			}
		}
	print(n, m);
	return 0;
}
