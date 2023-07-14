#include <iostream>
#include <cstring>
#include <algorithm>
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

const int N = 1e5 + 10;
const int K = 20;
int n, m;
int nums[N];

int solve(int x, int l, int r)
{
	for (int i = l; i <= r; i ++)
		x %= nums[i];
	return x;
}

inline void init()
{
	for (int k = 1; k <= K; k ++)
		for (LL i = 1; i <= n and i + (LL)(1 << k) - 1 <= 1e9; i ++)
			father[i][k] = father[father[i][k - 1]][k - 1];
}

inline int query(int now, int s)
{
	for (int k = K; k >= 0; k --)
	{
		if ((1 << k) <= s)
		{
			now = father[now][k];
			s -= (1 << k);
		}
	}
	return now;
}


int main()
{
	input(n), input(m);
	if (n * m <= 1e8)
	{
		for (int i = 1; i <= n; i ++)
			input(nums[i]);
		// input
		while (m --)
		{
			int x, l, r;
			input(x), input(l), input(r);
			cout << solve(x, l, r) << endl;
		}
		return 0;
	}
	// right but slow solution
	else
	{
		for (int i = 1; i <= n; i ++)
			input(nums[i]);
		// input
		while (m --)
		{
			int x, l, r;
			input(x), input(l), input(r);
			cout << solve(x, l, r) << endl;
		}
		
		init();
		
		// 没时间写了，是st表维护最小要模的值 
	}
	// wrong but fast solution
	// but it comes to be right
}
