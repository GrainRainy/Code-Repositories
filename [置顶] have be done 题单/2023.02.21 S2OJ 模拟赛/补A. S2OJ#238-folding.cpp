#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
const int INF = 1e8;
int n, cnt;
string a;
int dp[N][N];

int get_wei(int x)
{
	int tmp_count = 0;
	while (x) tmp_count ++, x /= 10;
	return tmp_count;
}

int loop(int l, int r, int gap)
{
	for (int i = 0; i <= r - l; i ++)
			if (a[l + i] != a[l + i % gap]) return INF;
	int nums = (r - l + 1) / gap;
	return get_wei(nums) + 2 + dp[l][l + gap - 1];
}

void init(int l, int r)
{
	int len = r - l + 1;
	for (int gap = 1; gap <= len; gap ++)
	{
		if (len % gap) continue;
		dp[l][r] = min(dp[l][r], loop(l, r, gap));
	}
}

int main()
{
	cin >> a;
	n = a.size();
	
	for (int len = 1; len <= n; len ++)
		for (int l = 0; l + len - 1 < n; l ++)
		{
			 int r = l + len - 1;
			 dp[l][r] = len;
			 init(l, r);
			 for (int k = l; k < r; k ++)
			 	dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
		}
	
	cout << dp[0][n - 1] << endl;
	return 0;
}
