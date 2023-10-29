#include <bits/stdc++.h>
using namespace std;

const int N = 60;

int n, c;
int pos[N], w[N];
int sum[N];
int f[N][N][2];

int main()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i ++)
	{
		cin >> pos[i] >> w[i];
		sum[i] = sum[i - 1] + w[i];
	}
	memset(f, 0x3f, sizeof f);
	f[c][c][0] = f[c][c][1] = 0;
	// init
	for (int len = 2; len <= n; len ++)
		for (int l = 1; l + len - 1 <= n; l ++)
		{
			int r = l + len - 1;
			f[l][r][0] = min(f[l + 1][r][0] + (pos[l + 1] - pos[l]) * (sum[n] - sum[r] + sum[l]), 
							 f[l + 1][r][1] + (pos[r] - pos[l]) * (sum[n] - sum[r] + sum[l]));
			f[l][r][1] = min(f[l][r - 1][1] + (pos[r] - pos[r - 1]) * (sum[n] - sum[r - 1] + sum[l - 1]),
							 f[l][r - 1][0] + (pos[r] - pos[l]) * (sum[n] - sum[r - 1] + sum[l - 1]));
		}
	cout << min(f[1][n][1], f[1][n][0]) << endl;
	return 0;
}
