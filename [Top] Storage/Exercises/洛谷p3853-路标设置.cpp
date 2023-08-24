#include <iostream>
#include <cctype>
#include <algorithm>
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
	if (x < 0) putchar ('-'), x = -x;
	static short st[30], idx;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
int nums[N];
int l, n, k;

inline bool judge(int x)
{
	int cnt = 0, now = nums[1];
	for(int i = 2; i <= n; i ++)
	{
		if(nums[i] - nums[i - 1] > x)
		{
			now = nums[i - 1];
			do
			{
		    	now += x;
		    	cnt ++;
			}
			while(nums[i] - now > x);
		}
		if(cnt > k) return false;
	}
	return true;
}

signed main()
{
	input(l), input(n), input(k);
	for (int i = 1; i <= n; ++ i)
		input (nums[i]);
	// input
	
	int bsl = 1, bsr = l;
	while (bsl < bsr)
	{
		int mid = bsl + bsr >> 1;
		if (judge(mid)) bsr = mid;
		else bsl = mid + 1;
	}
	cout << bsl << endl;
	return 0;
}
