#include <bits/stdc++.h>
typedef long long ll;
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

const int N = 5e5 + 10;

int n;
int nums[N], tmp[N];

ll merge_sort(int l, int r)
{
	if (l >= r) return 0;
	int mid = l + r >> 1;
	ll ans = merge_sort(l, mid) + merge_sort(mid + 1, r);
	
	int idx = 0;
	int i = l, j = mid + 1;
	while (i <= mid && j <= r)
		if (nums[i] <= nums[j]) tmp[idx ++] = nums[i ++];
		else
		{
			tmp[idx ++] = nums[j ++];
			ans += mid - i + 1;
		}
	while (i <= mid) tmp[idx ++] = nums[i ++];
	while (j <= r) tmp[idx ++] = nums[j ++];
	
	for (int i = 0, j = l; i < idx; i ++, j ++)
		nums[j] = tmp[i];
	return ans;
}

int main()
{
	input(n);
	for (int i = 0; i < n; ++ i) input(nums[i]);
	output(merge_sort(0, n - 1));
	return 0;
}
