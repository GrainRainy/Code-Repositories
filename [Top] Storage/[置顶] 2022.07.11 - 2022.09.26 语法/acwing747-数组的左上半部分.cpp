#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s;
	cin >> s;
	double a[15][15];
	for (int i = 0;i < 12;i ++)
		for (int j = 0;j < 12;j ++)
			cin >> a[i][j];
	
	double ans = 0;
	int cnt = 0;
	for (int i = 0;i < 12;i ++)
	{
		for (int j = 0;j < 11 - i;j ++)
		{
			ans += a[i][j];
			cnt ++;
		}
	}
	
	if (s == 'M') ans = ans * 1.0 / cnt;
	printf("%.1lf",ans);
	return 0;
}
