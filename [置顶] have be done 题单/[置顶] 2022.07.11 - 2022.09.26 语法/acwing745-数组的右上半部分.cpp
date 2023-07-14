#include <bits/stdc++.h>
using namespace std;
double a[15][15];
int main()
{
	char s;
	cin >> s;
	for (int i = 1;i <= 12;i ++)
		for (int j = 1;j <= 12;j ++)
			cin >> a[i][j];
	
	double ans = 0;
	for (int i = 1;i <= 12;i ++)
	{
		for (int j = 1;j <= 12;j ++)//或是j从i + 1开始 
		{
			if (j > i) ans += a[i][j];
		}
	}
	
	if (s == 'M') ans = ans * 1.0 / 66;
	printf("%.1lf",ans);
	return 0;
} 
