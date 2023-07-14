#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000;
int n, m;
// n 表示所有物品的个数，m 表示背包容量
int v[N + 10], w[N + 10];
// v 表示各个物品所占的体积，w 表示各个物品的价值 
int f[N + 10][N + 10];
// 状态 

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> v[i] >> w[i];
	
	// for (int j = 0; j <= m; j ++) f[0][j] = 0;
	// 一件物品都不选，可省略 
	
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j <= m; j ++)
		{
			f[i][j] = f[i - 1][j];
			// 不取 i 的情况
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
			// 能够装下 i 时取 i 的情况 
		}
		
	cout << f[n][m] << endl;
	return 0;
}
