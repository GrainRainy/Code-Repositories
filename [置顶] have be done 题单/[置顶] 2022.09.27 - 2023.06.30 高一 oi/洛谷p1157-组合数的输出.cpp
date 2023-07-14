#include <iostream>

using namespace std;

const int N = 25;

int n, r;

int path[N];

void dfs(int u)
{
	if (u == r + 1)
	{
		for (int i = 1; i <= r; i ++)
			printf("%3d", path[i]);
		cout << endl;
		return;
	}
	for (int i = path[u - 1] + 1; i <= n; i ++)
	{
		path[u] = i;
		dfs(u + 1);
	}
}

int main()
{
	cin >> n >> r;
	dfs(1);
	return 0;
}
