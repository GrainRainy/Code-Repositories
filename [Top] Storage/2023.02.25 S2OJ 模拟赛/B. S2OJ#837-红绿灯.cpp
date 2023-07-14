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
template <typename T>
inline void output(T x, char ed = ' ')
{
	static short st[30], idx;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
int n, m;
int nums[N];

int main()
{
	input(n), input(m);
	if (m == 0)
	{
		for (int i = 1; i <= n; ++ i)
			output(i);
		puts("");
		return 0;
	}
	if (m == 1)
	{
		int a; input(a);
		for (int i = 1; i <= a; ++ i)
			output(a);
		for (int i = a + 1; i <= n; ++ i)
			output(i);
		puts("");
		return 0;
	}
	if (m > 1000)
	{
		output(3), output(3);
		for (int i = 2; i <= n; i ++)
			output((i / 6 + 1) * 6);
		puts("");
		return 0;
	}
	// special situation
		
	for (register int i = 1; i <= m; ++ i)
	{
		int tmp; input(tmp);
		for (int j = 1; j <= n; ++ j)
			nums[j] = ceil(max(j, nums[j]) * 1.0 / tmp) * tmp;
	}
	for (register int i = 1; i <= n; ++ i)
		output(nums[i]);
	puts("");
	return 0;
}
