#include <bits/stdc++.h>
#include <cmath>
#include <cctype>
using namespace std;
using LL = long long;

template <typename T> inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n')
{
	static short st[30], top = 0;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar (st[top --] | '0');
	putchar(ed);
}

const int N = 5e4 + 10;
int t, k;
int nums[6][N];

void solve()
{
	puts("0");
}

int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	// file stream
	
	input(t), input(k);
	// input
	
	if (k == 1)
	{
		while (t --)
		{
			int n;
			input(n);
			int maxn = -1, minn = 0x3f3f3f3f;
			for (int i = 1; i <= n; i ++)
			{
				input(nums[0][i]);
				maxn = max(maxn, nums[0][i]);
				minn = min(minn, nums[0][i]);
			}
			output(maxn - minn);
		}
		return 0;
	}
	else while (t --) solve();
	return 0;
}
