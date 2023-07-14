#include <bits/stdc++.h>
using namespace std;

long long ans[25][25];
bool a[25][25];

void horse(int xh, int yh)
{
	a[xh][yh] = a[xh - 2][yh - 1]
			  = a[xh - 2][yh + 1]
	          = a[xh - 1][yh - 2]
			  = a[xh - 1][yh + 2]
			  = a[xh + 1][yh - 2]
			  = a[xh + 1][yh + 2]
			  = a[xh + 2][yh - 1]
			  = a[xh + 2][yh + 1]
			  = 1;
}

int main()
{
	int xb, yb, xh, yh;
	cin >> xb >> yb >> xh >> yh;
	xb += 2; yb += 2; xh += 2; yh += 2;
	horse(xh, yh);
	ans[1][2] = 1;
	for (int i = 2; i <= xb; i ++)
		for (int j = 2; j <= yb; j ++)
			if (!a[i][j]) ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
	
	cout << ans[xb][yb] << endl;
	return 0;
}
	

