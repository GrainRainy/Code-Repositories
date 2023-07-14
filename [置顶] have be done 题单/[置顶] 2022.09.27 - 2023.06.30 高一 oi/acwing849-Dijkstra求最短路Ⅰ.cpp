#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int map[N][N];
// 邻接矩阵存图
int n, m;
int dist[N];
// 存储点的距离 
bool st[N]; 
// 存储已经确定最短距离的点 

int dijkstra()
{	
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	for (int i = 0; i < n; i ++)
	// 迭代 n 次求最短路 
	{
		int t = -1;
		for (int j = 1; j <= n; j ++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		// 更新可扩展的最短路径 
		st[t] = true;
		// t 已确定最小值，标记为最短
		for (int j = 1; j <= n; j ++)
			dist[j] = min(dist[j], dist[t] + map[t][j]);
		// 使用 t 对新的最短边进行更新
		
	}
	if (dist[n] == 0x3f3f3f3f) return -1;
		// 特判无解 
		return dist[n]; 
}

int main()
{
	cin >> n >> m;
	memset(map, 0x3f, sizeof map);
	
	while (m --)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);
		// 处理重边与自环 
	}
	
	int t = dijkstra();
	
	cout << t << endl;
	
	return 0;
	
}
