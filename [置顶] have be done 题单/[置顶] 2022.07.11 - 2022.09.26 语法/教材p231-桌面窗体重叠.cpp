#include <bits/stdc++.h>

using namespace std;

short area[2005][2005] = {0};
int sum;

int main()
{
	int a, b, c, d;
	int e, f, g, h;
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	for (int i = a; i <= b; i ++)
		for (int j = c; j <= d; j ++)
			area[i][j] ++;
			
	for (int i = e; i <= f; i ++)
		for (int j = g; j <= h; j ++)
			area[i][j] ++;
	
	for (int i = 1; i <= 2000; i ++)
		for (int j = 1; j <= 2000; j ++)
			if (area[i][j] == 2) sum ++;
	cout << sum << endl;
	return 0;
}

