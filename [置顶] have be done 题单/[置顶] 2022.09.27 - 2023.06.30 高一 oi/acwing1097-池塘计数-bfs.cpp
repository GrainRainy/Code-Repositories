#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PII;

const int N = 1010;
int n, m;
int cnt;
char gph[N][N];
bool st[N][N];

queue<PII> q;

void bfs(int x, int y)
{
	st[x][y] = true;
	q.push({x, y});
	
	while (q.size())
	{
		auto t = q.front(); q.pop();
		
		for (int i = t.first - 1; i <= t.first + 1; i ++)
			for (int j = t.second - 1; j <= t.second + 1; j ++)
			{
				if (i < 0 or i >= n or j < 0 or j >= m) continue;
				if (gph[i][j] == '.' or st[i][j]) continue;
				
				q.push({i, j});
				st[i][j] = true;
			}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			cin >> gph[i][j];
	// input
	
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (gph[i][j] == 'W' and !st[i][j])
				bfs(i, j), cnt ++;

	cout << cnt << endl;
	return 0;
}
