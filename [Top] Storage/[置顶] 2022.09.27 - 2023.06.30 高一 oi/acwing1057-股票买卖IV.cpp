#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
const int M = 1e2 + 10;
int n, k;
int nums[N];
int f[N][M][2];
// [1 / 0] 表示当前手中是否持有股票 

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> nums[i];
	// inputf
	
	memset(f, 0xcf, sizeof f);
	for (int i = 0; i <= n; i ++)
		f[i][0][0] = 0; // 合法状态 
	// init
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= k; j ++)
		{
			f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + nums[i]);
			f[i][j][1] = max(f[i - 1][j - 1][0] - nums[i], f[i - 1][j][1]);
		}
			
	// dp
	
	int maxn = 0xcfcfcfcf;
	for (int i = 0; i <= k; i ++)
		maxn = max(maxn, f[n][i][0]);
	
	cout << maxn << endl;
	return 0;
}
