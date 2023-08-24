#include <bits/stdc++.h>
using namespace std;

double a[15][15];

int main()
{
	char s;
	cin >> s;
	for (int i = 0; i < 12; i ++)
		for (int j = 0; j < 12; j ++)
			cin >> a[i][j];
	
	double cnt = 0, sum = 0;
	for (int i = 1; i < 6; i ++)
	{
		for (int j = 12 - i; j <= 11; j ++)
		{
			sum += a[i][j];
			cnt ++;
		}
	}
	for (int i = 6; i < 11; i ++)
	{
		for (int j = i + 1; j <= 11; j ++)
		{
			sum += a[i][j];
			cnt ++;
		}
	}
	if (s == 'M') sum /= cnt;
	printf("%.1lf", sum);
	return 0;
}
