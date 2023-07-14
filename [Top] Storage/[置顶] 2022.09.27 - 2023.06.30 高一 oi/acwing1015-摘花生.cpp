#include <iostream>

using namespace std;

const int N = 110;

int g[N][N], f[N][N];

void solve()
{
	int r, c;
	cin >> r >> c;
	for (int i = 1; i <= r; i ++)
		for (int j = 1; j <= c; j ++)
		{
			cin >> g[i][j];
			f[i][j] = max(f[i - 1][j], f[i][j - 1]) + g[i][j];
		}
	
	cout << f[r][c] << endl;
	return;
}

int main()
{
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
