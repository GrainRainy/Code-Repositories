#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;

int n, m;
bool st[N][N];
char gph[N][N];
// basic things
int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int cnt;

void dfs(int x, int y)
{
	st[x][y] = true;
	for (int i = 0; i < 9; i ++)
			if (gph[x + dx[i]][y + dy[i]] == 'W' and !st[x + dx[i]][y + dy[i]])
				dfs(x + dx[i], y + dy[i]);
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
				dfs(i, j), cnt ++;
	
	cout << cnt << endl;
	return 0;
}
