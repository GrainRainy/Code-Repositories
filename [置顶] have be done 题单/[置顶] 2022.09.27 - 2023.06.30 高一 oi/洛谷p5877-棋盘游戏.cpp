#include <iostream>

using namespace std;

const int N = 505;

int map[N][N], father[N * N];

int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

int n, m, ans;

int find(int u)
{
	if (father[(u)] != u) father[u] = find(father[u]);
	return father[u];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i <= n * n; i ++)
		father[i] = i;
	// input
	
	for (int i = 1; i <= m; i ++)
	{
		int c, x, y;
		cin >> c >> x >> y;
		c ++;
		map[x][y] = c;
		ans ++;
		for (int j = 1; j <= 4; j ++)
		{
			int xx = x + dx[j];
			int yy = y + dy[j];
			if (map[xx][yy] != map[x][y]) continue;
			int p = find((xx - 1) * n + yy);
			int q = find((x - 1) * n + y);
			if (q != p) father[p] = q, ans --;
		}
		cout << ans << endl;
	}
	return 0;
}
