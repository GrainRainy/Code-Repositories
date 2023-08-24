#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int f[N][N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
		{
			cin >> tmp;
			if (i == 1 && j == 1) f[i][j] = tmp;
			else
			{
				f[i][j] = INT_MAX;
				if (i > 1) f[i][j] = min(f[i][j], f[i - 1][j] + tmp);
				if (j > 1) f[i][j] = min(f[i][j], f[i][j - 1] + tmp);
			}
		}
			
	cout << f[n][n] << endl;
	return 0;
}
