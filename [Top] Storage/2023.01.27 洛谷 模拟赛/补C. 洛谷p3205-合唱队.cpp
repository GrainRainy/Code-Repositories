#include <iostream>

using namespace std;

typedef long long LL;

const int N = 2e3 + 10;
const int MOD = 19650827;

int n;

int nums[N];
int f[2][N][N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> nums[i];
		f[0][i][i] = 1;
	}
	// input and init
	
	for (int len = 1; len <= n; len ++)
		for (int i = 1, j = i + len - 1; j <= n; i ++, j ++)
		{
			if (nums[i] < nums[i + 1]) f[0][i][j] += f[0][i + 1][j];
			if (nums[i] < nums[j]) f[0][i][j] += f[1][i + 1][j];
			if (nums[j] > nums[i]) f[1][i][j] += f[0][i][j - 1];
			if (nums[j] > nums[j - 1]) f[1][i][j] += f[1][i][j - 1];
			f[0][i][j] %= MOD, f[1][i][j] %= MOD;
		}
	
	LL ans = (f[0][1][n] + f[1][1][n]) % MOD;
	cout << ans << endl;
	return 0;
}
