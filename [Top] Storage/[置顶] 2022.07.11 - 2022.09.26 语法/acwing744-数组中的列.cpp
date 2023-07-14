#include <bits/stdc++.h>
using namespace std;

double a[15][15];

int main()
{
	int c;
	cin >> c;
	char s;
	cin >> s;
	
	for (int i = 0; i < 12; i ++)
		for (int j = 0; j < 12; j ++)
			cin >> a[i][j];
	
	double sum = 0;
	for (int i = 0; i < 12; i ++)
		sum += a[i][c];
	
	if (s == 'M') sum = sum / 12;
	printf("%.1lf",sum);
	return 0;
}
