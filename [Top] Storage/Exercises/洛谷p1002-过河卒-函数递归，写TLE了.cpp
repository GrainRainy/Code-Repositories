#include <bits/stdc++.h>
using namespace std;

int a[25][25];
int cnt;
int xb, yb;

void search(int x, int y)
{
	if (x == xb && y == yb) cnt ++;
	else if (x <= xb && y <= yb)
	{
		if (!a[x + 1][y])search(x + 1, y);
		if (!a[x][y + 1])search(x, y + 1);
	}
}

int main()
{
	int xh, yh;
	cin >> xb >> yb >> xh >> yh;
	a[xh][yh] = a[(xh - 2 < 0) ? 24 : xh - 2][(yh - 1 < 0) ? 24 : yh - 1]
			  = a[(xh - 2 < 0) ? 24 : xh - 2][yh + 1]
	          = a[(xh - 1 < 0) ? 24 : xh - 1][(yh - 2 < 0) ? 24 : yh - 2]
			  = a[(xh - 1 < 0) ? 24 : xh - 1][yh + 2]
			  = a[xh + 1][(yh - 2 < 0) ? 24 : yh - 2]
			  = a[xh + 1][yh + 2]
			  = a[xh + 2][(yh - 1 < 0) ? 24 : yh - 1]
			  = a[xh + 2][yh + 1]
			  = 1;
	search(0, 0);
	cout << cnt << endl;
	return 0;
}
