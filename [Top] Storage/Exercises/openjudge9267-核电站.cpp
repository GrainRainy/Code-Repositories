#include <iostream>

#define int long long 

using namespace std;

const int N = 55;

int dp[N][N];
// ǰ i�� ��λ�з��� j ��ը�� 

signed main()
{
	int n, m;
	cin >> n >> m;
	
	dp[0][0] = 1;
	// �߽��ʼ�� 
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j <= min(m - 1, i); j ++)
		{
			dp[i][0] += dp[i - 1][j];
			if (j >= 1) dp[i][j] += dp[i - 1][j - 1];
		}
			
		// put in
	}
	
	for (int i = 0; i <= n; i ++)
	{
		for (int j = 0; j <= m; j ++)
			cerr << dp[i][j] << " ";
			
		cerr << endl;
	}
		
	
	int cnt = 0;
	for (int i = 0; i <= m - 1; i ++)
		cnt += dp[n][i];
	
	cout << cnt << endl;
	
	return 0;
	
	
}

