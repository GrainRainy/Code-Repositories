#include <bits/stdc++.h>
using namespace std;

int a[22][22][22];
int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	int q;
	cin >> q; 
	while (q --)
	{
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		for (int i = 1; i <= x; i ++)
		{
			for (int j = 1; j <= y; j ++)
			{
				for (int k = 1; k <= z; k ++)
				{
					if (i >= x1 && i <= x2 && j >= y1 && j <= y2 && k >= z1 && k <= z2)
						a[i][j][k] = 1;
				}
			}
		}
		
	}
	int cnt = 0;
	for (int i = 1; i <= x; i ++)
	{
		for (int j = 1; j <= y; j ++)
		{
			for (int k = 1; k <= z; k ++)
			{
				if (!a[i][j][k]) cnt ++;
			}
		}
	}
	cout << cnt;
}
