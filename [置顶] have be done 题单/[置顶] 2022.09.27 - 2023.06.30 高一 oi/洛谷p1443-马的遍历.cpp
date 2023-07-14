#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int, int> PII;

const int N = 450;
int n, m;
int x, y;
int gph[N][N];

 struct node
{
	int x;int y;
}

int n;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

void bfs(int x, int y)
{
	gph[x][y] = 0;
	q.push({x, y});
	
	while (q.size())
	{
		auto t = q.front(); q.pop();
		
		for (int i = 0; i < 8; i ++)
		{
			int tmpx = t.first + dx[i];
			int tmpy = t.second + dy[i];
			
			if (tmpx <= 0 or tmpx > n or tmpy <= 0 or tmpy > m) continue;
			if (gph[tmpx][tmpy] == -1)
			{
				q.push({tmpx, tmpy});
				gph[tmpx][tmpy] = gph[t.first][t.second] + 1;
			}
		}
	}
}

int main()
{
	memset(gph, -1, sizeof gph);
	cin >> n >> m >> x >> y;
	bfs(x, y);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
			cout << gph[i][j] << " ";
		cout << endl;
	}
	return 0;
}
