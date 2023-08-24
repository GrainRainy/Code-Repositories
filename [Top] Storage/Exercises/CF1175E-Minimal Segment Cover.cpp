#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, ST = 20;

int n, m;
int f[N + 114514][25];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		int a, b;
		cin >> a >> b;
		f[a][0] = max(f[a][0], b);
	}
	for (int i = 1; i <= N; i ++)
		f[i][0] = max(f[i - 1][0], f[i][0]);
	for (int st = 1; st <= ST; st ++)
		for (int i = 0; i <= N; i ++)
			f[i][st] = f[f[i][st - 1]][st - 1];
	// init
	
	while (m --)
	{
		int x, y;
		cin >> x >> y;
		int ans = 0;
		for (int i = ST; i >= 0; i --)
			if (f[x][i] < y)
			{
				ans += (1 << i);
				x = f[x][i];
			}
			
		
		if (f[x][0] >= y) cout << ans + 1 << endl;
		else cout << "-1" << endl;
	}
	return 0;
}
