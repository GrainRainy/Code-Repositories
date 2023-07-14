#include <bits/stdc++.h>
using namespace std;
double a[15][15];
int main()
{
	int l;
	cin >> l;
	char s;
	cin >> s;
	for (int i = 0;i < 12;i ++)
		for (int j = 0;j < 12;j ++)
			cin >> a[i][j];
	double sum;
	for (int i = 0;i < 12;i ++)
		sum += a[l][i];
	if (s == 'M') sum = sum * 1.0 / 12;
	
	printf("%.1lf",sum);
	return 0;
}
