#include <bits/stdc++.h>
using namespace std;

double a[15][15];

int main()
{
	char t;
	cin >> t;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
			cin >> a[i][j];
	
	double sum = 0;
	int cnt = 0;
	for (int i = 7; i <= 11; i ++)
	{
		for (int j = 12 - i; j <= i - 1; j ++)
		{
			sum += a[i][j];
			cnt ++;
		}
	}
	
	if (t == 'M') sum /= cnt;
	printf("%.1lf",sum);
	return 0;
}
