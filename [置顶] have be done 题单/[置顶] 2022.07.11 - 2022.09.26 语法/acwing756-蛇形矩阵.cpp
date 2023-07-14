#include <bits/stdc++.h>
using namespace std;

int a[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0}; // Î»ÖÃÆ«ÒÆÁ¿ 

int main ()
{
	int n, m;
	cin >> n >> m;
	int d = 0; // 0right, 1down, 2left, 3up;
	int cnt = 1; // count;
	for (int x = 1, y = 1; cnt <= n * m; cnt ++)
	{
		a[x][y] = cnt;
		if (x + dx[d] > n || x + dx[d] < 1 || y + dy[d] > m || y + dy[d] < 1 || a[x + dx[d]][y + dy[d]])
			d = (d + 1) % 4;
		x = x + dx[d]; y = y + dy[d];
	}
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
