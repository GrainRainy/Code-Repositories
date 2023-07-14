#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template <typename T>
void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
void output(T x, char ed = '\n') // '\n' or ' ', remember to check
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++ tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp --] | '0');
	putchar(ed);
}

const int INF = 0x3f3f3f3f;
const int N = 210;
int n, t;
int nums[N];
// basic things
int f[N][N];
int val[N][N];
// dp

int main()
{
	freopen("revenant.in","r",stdin);
	freopen("revenant.out","w",stdout);
	input(n);
	for (int i = 1; i <= n; i ++)
		input(nums[i]);
	// input
	for (int i = 1; i <= n; i ++)
		f[i][i] = 1, val[i][i] = nums[i];
	
	for (int len = 2; len <= n; len ++)
		for (int l = 1; l + len - 1 <= n; l ++)
		{
			int r = l + len - 1;
			f[l][r] = INF;
			for (int k = l; k < l + len - 1; k ++)
			{
				if (f[l][k] == 1 && f[k + 1][r] == 1 && val[l][k] == val[k + 1][r])
					f[l][r] = 1, val[l][r] = val[l][k] + 1;
				else f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
			}
		}
	cout << f[1][n] << endl;
	return 0;
}

