
#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int INF = INT_MAX;

int mx[N][N], mn[N][N];

int n;
char c[N];
int nums[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> c[i] >> nums[i];
		c[i + n] = c[i], nums[i + n] = nums[i];
	}
	/*
	for (int i = 1; i <= 2 * n + 1; i ++)
		cerr << c[i]  << " " << nums[i] << " ";
	*/
	// input and trans
	for (int i = 1; i <= 2 * n; i ++)
		for (int j = 1; j <= 2 * n; j ++)
			if (i != j) mx[i][j] = -INF, mn[i][j] = INF;
			else mx[i][j] = mn[i][j] = nums[i];

	for (int len = 2; len <= n; len ++)
		for (int i = 1; i + len - 1 <= 2 * n; i ++)
		{
			int j = i + len - 1;
			for (int k = i; k < j; k ++)
				if (c[k + 1] == 't')
				{
					mx[i][j] = max(mx[i][j], mx[i][k] + mx[k + 1][j]);
					mn[i][j] = min(mn[i][j], mn[i][k] + mn[k + 1][j]);
				}
				else
				{
					mx[i][j] = max(max(max(mx[i][j], mx[i][k] * mx[k + 1][j]), max(mn[i][k] * mn[k + 1][j], mn[i][k] * mx[k + 1][j])), mx[i][k] * mn[k + 1][j]);
					mn[i][j] = min(min(min(mn[i][j], mx[i][k] * mx[k + 1][j]), min(mn[i][k] * mn[k + 1][j], mn[i][k] * mx[k + 1][j])), mx[i][k] * mn[k + 1][j]);
				}
		}

	int ans = -INF;
	for (int i = 1; i <= n; i ++)
		ans = max(ans, mx[i][i + n - 1]);
	cout << ans << endl;

	for (int i = 1; i <= n; i ++)
		if (mx[i][i + n - 1] == ans) cout << i << " ";

	return 0;
}
