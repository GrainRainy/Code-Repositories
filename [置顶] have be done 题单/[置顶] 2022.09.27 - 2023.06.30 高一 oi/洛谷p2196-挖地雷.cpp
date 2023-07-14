#include <iostream>

using namespace std;

const int N = 40;

int n;
int val[N]; // 地雷数 
bool map[N][N]; // 图 
bool st[N]; // 记录是否遍历过

int path[N], ans[N], cnt, maxx;

bool check(int x)
// 如果可以 WA 则返回 false 
{
	for (int i = 1; i <= n; i ++)
		if (map[x][i] && !st[i]) return false;
	return true;
}

void dfs(int x, int step, int sum)
{
	if (check(x))
	{
		if (maxx < sum)
		{
			maxx = sum;
			cnt = step;
			for (int i = 1; i <= step; i ++)
				ans[i] = path[i];
		}
		return;
	}
	
	for (int i = 1; i <= n; i ++)
	{
		if (map[x][i] && !st[i])
		{
			st[i] = 1;
			path[step + 1] = i;
			dfs(i, step + 1, sum + val[i]);
			st[i] = 0;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> val[i];

	for (int i = 1; i < n; i ++)
		for (int j = i + 1; j <= n; j ++)
			cin >> map[i][j];
	// input
	for (int i = 1; i <= n; i ++)
	{
		st[i] = 1;
		path[1] = i;
		
		dfs(i, 1, val[i]);
		
		st[i] = 0;
	}
	
	for (int i = 1; i <= cnt; i ++)
		cout << ans[i] << " ";
	cout << endl << maxx;
	
	return 0;
}
