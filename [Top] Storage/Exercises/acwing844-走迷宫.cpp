#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int n, m;
int map[N][N], d[N][N];
// map存储地图，d存储每一个点到起点的距离 
PII q[N * N];
// 模拟队列
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// 位置偏移向量
PII Prev[N][N];


int bfs()
{
	int hh = 0,  tt = 0;
	q[0] = {0, 0};
	// 队列初始化
	memset(d, -1, sizeof d);
	// 初始化为 -1 的点表示没有走过 
	d[0][0] = 0;
	
	while (hh <= tt)
	// 队列不空 
	{
		auto t = q[hh ++];
		
		for (int i = 0; i < 4; i ++)
		{
			int x = t.first + dx[i], y = t.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && !map[x][y] && d[x][y] == -1)
			{
				d[x][y] = d[t.first][t.second] + 1;
				Prev[x][y] = t;
				q[ ++ tt ] = {x, y};
			}
		}
	}
	
	return d[n - 1][m - 1];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			cin >> map[i][j];
	
	cout << bfs() << endl;
	
	return 0;
}
