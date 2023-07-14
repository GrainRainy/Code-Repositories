#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

bool gragh[N][N];
int l[N], r[N];

int n, m;

int main()
{
	cin >> n >> m;
	getchar();
	memset(l, 0x3f, sizeof l);
	memset(r, -1, sizeof r);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			char c = getchar();
			if (c == 'J')
			{
				l[i] = min(l[i], j);
				r[i] = max(r[i], j);
				gragh[i][j] = true;
			}
		}
		getchar();
	}
	
	int ans = 0;
	int sny = 1;
	for (int i = n; i > 1; i --)
	{
		if (l[i] > r[i]) ;
		if (l[i - 1] > r[i - 1])
		{
			if (l[i] < r[i])
			{
				ans += r[i] - l[i];
				sny = r[i];
			}
		}
		else if (((n - i) % 2)  && l[i - 1] < sny)
		{
			if (l[i] != 0x3f3f3f3f)
			{
				ans += sny - min(l[i - 1], l[i]);
				sny = min(l[i - 1], l[i]);
			}
			else
			{
				ans += sny - l[i - 1];
				sny = l[i - 1];
			}
			
		}
		else if ((n - i) % 2 == 0 && r[i - 1] > sny)
		{
			if (r[i] != -1)
			{
				ans += max(r[i - 1], r[i]) - sny;
				sny = max(r[i - 1], r[i]);
			}
			else
			{
				ans += r[i - 1] - sny;
				sny = r[i - 1];
			}
		}
		ans ++;
	}
	
	if (l[1] > r[1]) ans --;
	if (l[1] < sny) ans += sny - l[1];
	else if (r[1] > sny) ans += r[1] - sny; 
	
	cout << ans << endl;
}
