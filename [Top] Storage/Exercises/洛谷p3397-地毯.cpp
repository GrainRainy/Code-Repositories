#include <iostream>

using namespace std;

const int N = 1000;
int n, m;
int sum[N + 10][N + 10];
int ans[N + 10][N + 10];

void insert(int x1, int y1, int x2, int y2)
{
	sum[x1][y1] += 1;
	sum[x1][y2 + 1] -= 1;
	sum[x2 + 1][y1] -= 1;
	sum[x2 + 1][y2 + 1] += 1;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		insert(x1, y1, x2, y2);
	}
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + sum[i][j];
			
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
			cout << ans[i][j] << " ";
		cout << endl;
	}

	return 0;
}
