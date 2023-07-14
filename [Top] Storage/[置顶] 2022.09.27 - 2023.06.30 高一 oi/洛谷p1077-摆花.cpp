#include <iostream>

using namespace std;

const int N = 1e2 + 10, MOD = 1e6 + 7;

int n, m;
int items[N];
int dp[N][N];


int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> items[i];
	// input
	dp[0][0] = 1;
	
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j <= m; j ++)
			for (int k = 0; k <= min(j, items[i]); k ++)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
	
	cout << dp[n][m] << endl;
}
