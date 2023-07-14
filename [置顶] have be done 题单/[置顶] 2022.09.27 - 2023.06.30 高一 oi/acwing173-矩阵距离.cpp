#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1010;
int n, m;
char gph[N][N];
int dist[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<PII> q;

void bfs()
{
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (gph[i][j] == '1') 
				dist[i][j] = 0, q.push({i, j});
	// input
	
	while (q.size())
	{
		auto t = q.front(); q.pop();
		
		for (int i = 0; i < 4; i ++)
		{
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			
			if (nx <= 0 or nx > n or ny <= 0 or ny > m) continue;
			if (dist[nx][ny] != -1) continue;
			
			dist[nx][ny] = dist[t.first][t.second] + 1;
			q.push({nx, ny});
		}
	}
}

int main()
{
	memset(dist, -1, sizeof dist);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> gph[i] + 1;
	// input
	bfs();
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
			cout << dist[i][j] << " ";
		cout << endl;
	}
	return 0;
}
