#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;

int na, nb;
char a[N], b[N];
int f[N][N];

int main()
{
	cin >> na >> a + 1 >> nb >> b + 1;
	
	for (int j = 1; j <= nb; j ++)
		f[0][j] = j;
	for (int i = 1; i <= na; i ++)
		f[i][0] = i;
	// 一定要注意边界的初始化 
	
	for (int i = 1; i <= na; i ++)
		for (int j = 1; j <= nb; j ++)
		{
				f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			if (a[i] != b[j])
				f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
			else f[i][j] = min(f[i][j], f[i - 1][j - 1]);
		}
	
	cout << f[na][nb] << endl;
	
	return 0;
}
