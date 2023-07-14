#include <iostream>
#include <cstring> 
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 160;
int n, m; // basic things
int sx, sy; // start
int fx, fy; // finally
char gph[N][N]; // graph
int dist[N][N]; // distance
queue<PII> q;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, 2, -2, 2, -2, 1, -1};

int dfs(int x, int y)
{
	q.push({x, y}); dist[x][y] = 0;
	
	while (q.size())
	{
		auto t =q.front(); q.pop();
		
		for (int i = 0; i < 8; i ++)
		{
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			
			if (nx <= 0 or nx > n or ny <= 0 or ny > m) continue;
			if (~dist[nx][ny]) continue;
			if (gph[nx][ny] == '*') continue;
			if (gph[a][b] == 'H') return dist[t.first][t.first] + 1;
			
			q.push({nx, ny});
			dist[nx][ny] = dist[t.first][t.second] + 1;
		}
	}
}

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
		{
			cin >> gph[i][j];
			if (gph[i][j] == 'K')
				sx = i, sy = j;
			if (gph[i][j] == 'H')
				fx = i, fy = j;
		}
	// input
	memset(dist, -1, sizeof dist);
	cout << dfs(sx, sy) << endl;
	return 0;
}
