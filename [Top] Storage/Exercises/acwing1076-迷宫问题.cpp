#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1010;
int n;
bool gph[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
PII path[N][N];
queue<PII> q;

void bfs(int x, int y)
{
	q.push({x, y}); path[x][y] = {0, 0};
	
	while (q.size())
	{
		auto t = q.front(); q.pop();
		for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 4; j ++)
		{
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			if (nx <= 0 or nx > n or ny <= 0 or ny > n) continue;
			if (gph[nx][ny]) continue;
			if (~path[nx][ny].first) continue;
			
			q.push({nx, ny});
			path[nx][ny] = t;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			cin >> gph[i][j];
	// input
	memset(path, -1, sizeof path);
	PII end = {1, 1};
	bfs(n, n);
	
	
	while (1)
	{
		cout << end.first - 1 << " " << end.second - 1 << endl;
		if (end.first == n and end.second == n) break;
		end = path[end.first][end.second];
	}
	return 0;
}
