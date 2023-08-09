#include <bits/stdc++.h>
using namespace std;
template <typename T>
void input(T &x)
{
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
void output(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++ tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp --] | '0');
	putchar(ed);
}
/*
 *  or ' ', remember to check
 */

const int N = 60;

int n, c;
int lamps[N];
int cost[N];
int f[N][N][N];

int dp(int i, int j, int k)
{
	int ans = 0x3f3f3f3f;
	for (int q = 1; q <= n; q ++)
	{
		if (q == k) continue;
		ans = min(ans, dp(k, j - 1, q) + abs(lamps[i] - lamps[k]));
	}
	return ans;
}

int main()
{
	input(n), input(c);
	for (int i = 1; i <= n; i ++)
		input(lamps[i]), input(cost[i]);
		
	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= n; i ++)
		for (int k = 1; k <= n; k ++)
		{
			if (k == i) continue;
			ans = min(ans, dp(i, n, k));
		}
			
	cout << ans << endl;
	return 0;
}
