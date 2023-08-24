#include <bits/stdc++.h>

using namespace std;

int mov[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int numx[12][12];

int main()
{
	int n;
	cin >> n;
	int direction = 0;
	int x = 1, y = 1;
	for (int i = 1; i <= n * n; i ++)
	{
		numx[x][y] = i;
		if (x + mov[direction][0] <= 0 || x + mov[direction][0] > n || y + mov[direction][1] <= 0 || y + mov[direction][1] > n || numx[x + mov[direction][0]][y + mov[direction][1]])
			direction = (direction + 1) % 4;
		x = x + mov[direction][0];
		y = y + mov[direction][1];
	}
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
		printf("%3d", numx[i][j]);
		cout << endl;
	}
		
	
	return 0;		
}
