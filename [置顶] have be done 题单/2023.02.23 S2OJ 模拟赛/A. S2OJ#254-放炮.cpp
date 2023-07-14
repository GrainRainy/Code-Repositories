#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x; 
}

typedef long long LL;
const int N = 110;
const int MOD = 9999973;
int n, m;

int x[N], y[N];
bool save[N][N];
int cnt;

void dfs(int i, int maxn)
{
//	cout << endl;
//	for (int i = 1; i <= n; i ++)
//	{
//		for (int j = 1; j <= m; j ++)
//			cout << save[i][j] << " ";
//		cout << endl;
//	}
//	cout << endl;
	if (!maxn or i > n) return;
			
	for (int j = 1; j <= m; j ++)
		for (int k = j; k <= m; k ++)
		{
			if (k != j and y[k] < 2 and y[j] < 2 and !save[i][j] and !save[i][k])
			{
				cnt ++;
				save[i][j] = save[i][k] = true, y[j] ++, y[k] ++;
				dfs(i + 1, maxn - 2);
				save[i][j] = save[i][k] = false, y[j] --, y[k] --;
			}
		}
	
}

int main()
{
	input(n), input(m);
	cnt = n * m + 1; // 1 and 0
	for (int i = 1; i <= n; i ++)
		for (int num = 2; num <= 2 * min(n, m); num ++)
			dfs(i, num);
	cout << cnt << endl;
	return 0;
}

//typedef long long LL;
//const int N = 110;
//const int MOD = 9999973;
//int n, m;
//int f[N][N][2][3][3];
//
//int cal_all(int i, int j)
//{
//	int sum = 0;
//	for (int k = 0; k < 3; k ++)
//		for (int t = 0; t < 3; t ++)
//		{
//			sum = (sum + f[i][j][0][k][t]) % MOD;
//			if (k >= 1 and t >= 1)
//				sum = (sum + f[i][j][1][k][t]) % MOD;
//		}
//	return sum;
//}
//
//int cal_x(int x, int y)
//{
//	int cnt = 0;
//	for (int i = 1; i <= x; i ++)
//		
//}
//
//int cal_y(int x, int y)
//{
//	
//}
//
//int main()
//{
//	input(n), input(m);
//	
//	f[0][0][0][0][0] = 1;
//	for (int i = 1; i <= n + 1; i ++)
//		for (int j = 1; j <= m + 1; j ++)
//		{
//			f[i][j][0][0][0] = ((LL)f[i][j][0][0][0] + cal(i - 1, j - 1)) % MOD;
//			f[i][j][0][1][0] = ((LL)f[i][j][0][1][0] + f[i][j - 1][0][1][0] + f[i][j - 1][0][1][1] + f[i][j - 1][0][1][2] + f[i][j - 1][1][1][1] + f[i][j - 1][1][1][2]) % MOD;
//			f[i][j][0][2][0] = ((LL)f[i][j][0][2][0] + f[i][j - 1][0][2][0] + f[i][j - 1][0][2][1] + f[i][j - 1][0][2][2] + f[i][j - 1][1][2][1] + f[i][j - 1][1][2][2]) % MOD;
//			f[i][j][0][0][1] = 
//			f[i][j][0][0][2] = ((LL)f[i][j][0][0][2] + f[i - 1][j][0][0][2] + f[i - 1][j][0][1][2] + f[i - 1][j][0][2][2] + f[i - 1][j][1][1][1])
//			f[i][j][0][1][1] = ((LL)f[i][j][0][1][1] + ) % MOD;
//			f[i][j][0][2][1] = ((LL)f[i][j][0][2][1] + ) % MOD;
//			f[i][j][0][1][2] = ((LL)f[i][j][0][1][2] + ) % MOD;
//			f[i][j][0][2][2] = ((LL)f[i][j][0][2][2] + ) % MOD;
//			f[i][j][1][1][1] = ((LL)f[i][j][1][1][1] + ) % MOD;
//			f[i][j][1][2][1] = ((LL)f[i][j][1][2][1] + ) % MOD;
//			f[i][j][1][1][2] = ((LL)f[i][j][1][1][2] + ) % MOD;
//			f[i][j][1][2][2] = ((LL)f[i][j][1][2][2] + ) % MOD;
//		}
//	cout << f[n + 1][m + 1][0][0][0] << endl;
//	return 0;
//}

