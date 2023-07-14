#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

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
	static short st[64], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5;
const int K = 17;
int n, m; 
int nums[N + 10];
int minn[N + 10][K + 10];

inline void init()
{
	for (int k = 0; k <= K; k ++)
		for (int i = 1; i + (1 << k) - 1 <= n; i ++)
		{
			if (!k) minn[i][k] = nums[i];
			else minn[i][k] = min(minn[i][k - 1], minn[i + (1 << k - 1)][k - 1]);
		}
}

inline int query(int l, int r)
{
	int len = r - l + 1;
	int need = log2(len);
	return min(minn[l][need], minn[r - (1 << need) + 1][need]);
}
///*
inline void solve(int x, int l, int r)
{
	int tmpl = l, tmpr = r;
	while (1)
	{
		tmpr = r;
		if (tmpl > tmpr) return output(x), void();
		while (tmpl < tmpr)
		{
			int mid = tmpl + tmpr >> 1;
			if (query(tmpl, mid) <= x) tmpr = mid;
			else tmpl = mid + 1;
		}
		x %= nums[tmpr]; tmpl = tmpr + 1;
	}
}
//*/
int main()
{
	input(n), input(m);
	for (int i = 1; i <= n; i ++)
		input(nums[i]);
	init();
	// input and init
	
	while (m --)
	{
		int x, l, r;
		input(x), input(l), input(r);
		solve(x, l, r);
	}
	return 0;
}
