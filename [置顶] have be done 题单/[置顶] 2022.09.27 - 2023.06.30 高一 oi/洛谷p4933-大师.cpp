#include <iostream>

using namespace std;

const int N = 1e3 + 10, H = 4e4, MOD = 998244353;

int n;
int height[N];
int dp[N][H];
long long ans;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> height[i];
	// input
	
	for (int i = 1; i <= n; i ++)
	{
		ans ++;
		for (int j = i - 1; j; j --)
		{
			int k = height[i] - height[j] + H;
			dp[i][k] += dp[j][k] + 1;
			dp[i][k] %= MOD;
			ans += dp[j][k] + 1;
			ans %= MOD;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
