#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 150 + 10;
const int K = 20 + 10;
const int MOD = 12345678;
int n, m, k;
int f[N][N][K][K];
// boy, girl, boy - girl, girl - boy

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	f[0][0][0][0] = 1;
	// input and init
	for (int i = 0; i <= n; ++ i)
		for (int j = 0; j <= m; ++ j)
			for (int u = 0; u <= k; ++ u)
				for (int v = 0; v <= k; ++ v)
					if (f[i][j][u][v]){
						f[i + 1][j][u + 1][max(v - 1, 0)] = (f[i + 1][j][u + 1][max(v - 1, 0)] + f[i][j][u][v]) % MOD;
						f[i][j + 1][max(u - 1, 0)][v + 1] = (f[i][j + 1][max(u - 1, 0)][v + 1] + f[i][j][u][v]) % MOD;
					}
	
	int ans = 0;
	for (int i = 0; i <= k; ++ i)
		for (int j = 0; j <= k; ++ j)
			ans = (ans + f[n][m][i][j]) % MOD;
	cout << ans << endl;
	return 0;
}
