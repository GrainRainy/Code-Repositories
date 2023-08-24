#include <iostream>

using namespace std;

const int N = 210;

int graph[N][N];

int n, m, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= n; j ++)
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = 0x3f3f3f3f;
	
	for (int i = 1; i <= m; i ++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		graph[x][y] = min(graph[x][y], z);
	}
	
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
	
	for (int i = 1; i <= k; i ++)
	{
		int x, y;
		cin >> x >> y;
		if (graph[x][y] > 0x3f3f3f3f / 2)
			cout << "impossible" << endl;
		else cout << graph[x][y] << endl;
	}
	return 0;
}
