#include <iostream>

using namespace std;

const int N = 510;
const int INF = -1e9;

int n;
int map[N][N];
int f[N][N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= i; j ++)
			cin >> map[i][j];
			
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= i + 1; j ++)
			f[i][j] = INF;
	
	f[1][1] = map[1][1];
	
	for (int i = 2; i <= n; i ++)
		for (int j = 1; j <= i; j ++)
			f[i][j] = max(f[i - 1][j -  1], f[i - 1][j]) + map[i][j];
			
	int cnt = INF;
	
	for (int i = 1; i <= n; i ++)
		cnt = max(cnt, f[n][i]);
	
	cout << cnt << endl;
	
	return 0;
}
