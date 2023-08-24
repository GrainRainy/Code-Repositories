#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<int, int> PII;
const int N = 510;
const int M = N * N; 
int r, c;
char gph[N][N];
int dist[N][N];
bool st[N][N];

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

char cs[] = "\\//\\";
int lx[] = {-1, -1, 0, 0};
int ly[] = {-1, 0, -1, 0};

int bfs()
{
	memset(st, 0, sizeof st);
	memset(dist, 0x3f, sizeof dist);
	
	deque<PII> q;
	dist[1][1] = 0; q.push_front({1, 1});
	
	while (q.size())
	{
		auto t = q.front(); q.pop_front();
		int x = t.first, y = t.second;
		
		if (st[x][y]) continue;
		st[x][y] = true;
	
	    for (int i = 0; i < 4; i ++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			int cx = x + lx[i], cy = y + ly[i];
			if (nx <= 0 or nx > r + 1 or ny <= 0 or ny > c + 1) continue;
			
			int d = dist[x][y] + (gph[cx][cy] != cs[i]);
			if (d < dist[nx][ny])
			{
				dist[nx][ny] = d;
				
				if (gph[cx][cy] != cs[i]) q.push_back({nx, ny});
				else q.push_front({nx, ny});
			}
		}
	}
	return dist[r + 1][c + 1];
}

int main()
{
	cin >> r >> c;
	for (int i = 1; i <= r; i ++)
		for (int j = 1; j <= c; ++ j)
			cin >> gph[i][j];
	// input
	int ans = bfs();
	if (ans == 0x3f3f3f3f) puts("NO SOLUTION");
	else cout << ans << endl;
	return 0;
}
