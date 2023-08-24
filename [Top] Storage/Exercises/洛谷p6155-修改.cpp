#include <iostream>
#include <algorithm>
#include <cctype>
typedef unsigned long long ULL;
template <typename T>
void read(T &x)
{
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
void print(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++ tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp --] | '0');
	putchar(ed);
}

using namespace std;

const int N = 1e6 + 100;
const int ai = 1e9;

int n;
int nums[N], cost[N], costidx;
int stk[N], top; // stack
long long gapidx;
long long gap[N];

int main()
{
	read(n);
	for (int i = 1; i <= n; i ++)
		read(nums[i]);
	for (int i = 1; i <= n; i ++)
		read(cost[i]);
	sort(nums + 1, nums + n + 1);
	sort(cost + 1, cost + n + 1);
	// input and init
	int idx = 1, i = 1;
	// i ±éÀúÖµÓò, idx ±éÀúÐòºÅ 
	// ×¢Òâ£ºnums[idx] »¹Î´´æ´¢
	while (i <= nums[n] || top)
	{
		if (!top && nums[idx] != i) 
			i = nums[idx];
		if (i == nums[idx])
			stk[++ top] = nums[idx ++];
		for (i; nums[idx] == nums[idx - 1] && i <= ai;)
			stk[++ top] = nums[idx ++];
		gap[++ gapidx] = i - stk[top --];
		i ++;
	}
	sort(gap + 1, gap + gapidx + 1, greater<int>());
	ULL ans = 0;
	for (int i = 1; i <= gapidx; i ++)
		ans = ans +  gap[i] * cost[i];
	cout << ans << endl;
	return 0;
}
