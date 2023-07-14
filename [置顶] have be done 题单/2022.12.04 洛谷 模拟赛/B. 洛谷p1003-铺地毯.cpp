#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int grd[N][4];
// begin with 1, begin with 0
// N refers to the numbers of ^^^
// 4 regers to the a, b, lx, ly

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n ; i ++)
		cin >> grd[i][0] >> grd[i][1] >> grd[i][2] >> grd[i][3];
	// input
	
	int x, y;
	cin >> x >> y;
	for (int i = n; i > 0; i --)
	{
		int bx = grd[i][0], by = grd[i][1];
		int ex = bx + grd[i][2] - 1, ey = by + grd[i][3] - 1;
		if (x >= bx && y >= by && x <= ex && y <= ey)	
		{
			cout << i << endl;
			return 0;
		}
		else if (i == 1)
		{
			cout << -1 << endl;
		}
	}
	// search
	
	return 0;
}
