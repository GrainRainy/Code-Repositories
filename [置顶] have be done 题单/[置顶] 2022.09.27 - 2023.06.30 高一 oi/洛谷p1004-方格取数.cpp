#include <iostream>
#include <cctype>
#include <cstring>
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
template <typename T>
inline void output(T x, char ed = '\n')
{
	if (x < 0) putchar("-"), x = -x;
	static short st[30], idx;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

const int N = 12;
int n;
int a, b, c;
int gph[N][N];
int dp[N][N][N << 1];
// i1, i2, sum

signed main()
{
	memset(dp, 0xcf, sizeof dp);
	dp[0][0][1] = gph[0][0];
	input(n);
	
	while (1)
	{
		input(a), input(b), input(c);
		if (!a && !b && !c) break;
		gph[a][b] = c;
	}
	// input
	for (int sum = 2; sum <= (n << 1); sum ++)
		for (int i1 = 1; i1 <= n; i1 ++)
			for (int i2 = 1; i2 <= n; i2 ++)
			{
				int tmp = &dp[i1][i2][sum];
				tmp = max(tmp, dp[i1 - 1][i2][sum - 1]);
				tmp = max(tmp, dp[i1][i2 - 1][sum - 1]);
				tmp = max(tmp, dp[i1 - 1][i2 - 1][sum - 1]);
				tmp = max(tmp, dp[i1][i2][sum - 1]);
				if (i1 == i2) tmp += gph[i1][sum - i1];
				else tmp += gph[i1][sum - i1] + gph[i2][sum - i2];
			}
	cout << dp[n][n][n << 1] << endl;
	return 0;
}
