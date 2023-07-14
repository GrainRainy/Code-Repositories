#include <bits/stdc++.h>
using namespace std;

const int N = 25;
const int M = 1 << 20;
int n;
int graph[N][N];
int f[M][N];
// state and points which stayed at 

int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			cin >> graph[i][j];
	// input
	memset(f, 0x3f, sizeof f);
	// init
	f[1][0] = 0;
	for (int i = 0; i < 1 << n; i ++)	
		for (int j = 0; j < n; j ++)
			if (i >> j & 1)
				for (int k = 0; k < n; k ++)
					if (i - (1 << j) >> k & 1)
						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + graph[k][j]);
	// dp
	cout << f[(1 << n) - 1][n - 1] << endl;
	return 0;
}
