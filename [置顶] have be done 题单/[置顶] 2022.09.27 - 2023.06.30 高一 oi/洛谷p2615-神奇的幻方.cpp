#include <iostream>
#define endl '\n'

using namespace std;

int ans[45][45];

int main()
{
	int n;
	cin >> n;
	ans[1][n / 2 + 1] = 1;
	int savex = 1, savey = n / 2 + 1;
	
	for (int i = 2; i <= n * n; i ++)
	{
		if (savex == 1 && savey != n)
		{
			ans[n][++ savey] = i;
			savex = n;
		}
		else if (savey == n && savex != 1)
		{
			ans[-- savex][1] = i;
			savey = 1;
		}
		else if (savex == 1 && savey == n)
			ans[++ savex][savey] = i;
			
		else
			if (ans[savex - 1][savey + 1] == 0)
				ans[-- savex][++ savey] = i;
			else
				ans[++ savex][savey] = i;
		
	}
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	
	return 0;
}

