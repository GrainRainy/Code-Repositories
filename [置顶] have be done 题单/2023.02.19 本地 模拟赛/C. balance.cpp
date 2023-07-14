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
inline void output(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], idx = 0;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

const int N = 510;
const int M = 20010;
int n, m;
int nums[N];
bool st[M];
int cnt;

void dfs(int u, int sum)
{
	if (u == n) return;
	for (int i = u + 1; i < n; i ++)
	{
		if (sum + nums[i] > 0)
		{
			st[sum + nums[i]] = true;
			dfs(i, sum + nums[i]);
		}
		if (sum - nums[i] > 0)
		{
			st[sum - nums[i]] = true;
			dfs(i, sum - nums[i]);
		}
	}
	
}

int main()
{
	freopen("balance.in", "r", stdin);
	freopen("balance.out", "w", stdout);
	input(n);
	for (int i = 0; i < n; i ++)
	{
		input(nums[i]);
		st[nums[i]] = true;
	}
		
	// input
	sort(nums, nums + n, greater<int>());
	for (int i = 0; i < n; i ++)
	{
		dfs(i, nums[i]);
		dfs(i, -nums[i]);
	}
	// dfs
	for (int i = 1; i <= 20010; i ++)
		if (st[i]) cnt ++;
	output(cnt);
	return 0;
}
