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
			
	double sum = 0;
	int cnt = 0;
	for (int i = 0;i <= 4;i ++)
	{
		for (int j = i + 1;j <= 10 - i;j ++)
		{
			cnt ++;
			sum += a[i][j];
		}
	}
	
	if (s == 'M') sum = sum * 1.0 / cnt;
	printf("%.1lf",sum);
	return 0;
}
