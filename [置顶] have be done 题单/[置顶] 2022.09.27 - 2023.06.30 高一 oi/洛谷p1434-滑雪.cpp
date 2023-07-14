#include <iostream>

using namespace std;

const int N = 110;
int map[N][N], save[N][N];
int r, c;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y)
{
	if (save[x][y]) return save[x][y];
	save[x][y] = 1;
	for (int i = 0; i < 4; i ++)
	{
		int temx = x + dx[i], temy = y + dy[i];
		if (temx && temy && temx <= r && temy <= c && map[x][y] > map[temx][temy])
		{
			dfs(temx, temy);
			save[x][y] = max(save[x][y], save[temx][temy] + 1);
		}
	}
	return save[x][y];
}

int main()
{
	cin >> r >> c;
	for (int i = 1; i <= r; i ++)
		for (int j = 1; j <= c; j ++)
			cin >> map[i][j];
		
	int maxh = 0;
	for (int i = 1; i <= r; i ++)
		for (int j = 1; j <= c; j ++)
			maxh = max(dfs(i, j), maxh);
	
	cout << maxh << endl;
	
	return 0;
}
