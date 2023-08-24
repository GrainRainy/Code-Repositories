#include <bits/stdc++.h>
using namespace std;

int a[105][105];

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	while (m --)
	{
		int x, y;
		cin >> x >> y;
		for (int i = x - 1; i <= x + 1; i ++)
			for (int j = y - 1; j <= y + 1; j ++)
				a[i][j] = 1;
		a[(x - 2 < 0) ? 0 : x - 2][y] = a[x + 2][y] = a[x][(y - 2 < 0) ? 0 : y - 2] = a[x][y + 2] = 1;
	}
	while (k --)
	{
		int o, p;
		cin >> o >> p;
		for (int i = (o - 2 < 0) ? 0 : o - 2; i <= o + 2; i ++)
			for (int j = (p - 2 < 0) ? 0 : p - 2; j <= p + 2; j ++)
				a[i][j] = 1;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (!a[i][j]) cnt ++;
	cout << cnt << endl;
	
	return 0;
}
