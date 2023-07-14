#include <iostream>

using namespace std;

const int N = 20;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];
// 分别表示：列，正对角线(左下到右上)，反对角线 
void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0; i < n; i ++)
			puts(g[i]);
		cout << endl;
		return;
	}
	
	for (int i = 0; i < n; i ++)
		if (!col[i] && !dg[u + i] && !udg[n - u + i])
		{
			g[u][i] = 'Q';
			col[i] = dg[u + i] = udg[n - u + i] = true;
			dfs(u + 1);
			col[i] = dg[u + i] = udg[n - u + i] = false;
			g[u][i] = '.';
		}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			g[i][j] = '.';
	
	dfs(0);
	
	return 0; 
}
