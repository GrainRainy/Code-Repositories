#include <bits/stdc++.h>
using namespace std;
double a[15][15];
int main()
{
	char s;
	cin >> s;
	for (int i = 0;i < 12;i ++)
		for (int j = 0;j < 12;j ++)
			cin >> a[i][j];
	
	int cnt = 0;
	double ans = 0;
	for (int i = 1;i <= 5;i ++)
	{
		for (int j = 0;j < i;j ++)
		{
			cnt ++;
			ans += a[i][j];
		}
	}
	for (int i = 6;i <= 10;i ++)
	{
		for (int j = 0;j <= 10 - i;j ++)
		{
			cnt ++;
			ans += a[i][j];
		}
	}

	if (s == 'M') ans = ans / cnt;
	printf("%.1lf",ans);
	return 0;
}
