#include <cctype>
#include <algorithm>
using namespace std;
template <typename T>
inline void input(T &x)
{
	x = 0; char c = getchar();
	for (; !isdigit(c); )
		c = getchar();
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
}
template <typename T>
inline void output(T x, char ed = '\n')
{
	static short st[30], idx;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}
const int N = 2e5 + 10;
int n, nums[N], ans;
int main()
{
	input(n);
	for (int i = 1; i <= n; ++ i) input(nums[i]);
	nums[n + 1] = 0x3f3f3f3f;
	sort(nums + 1, nums + n + 1);
	int maxn = unique(nums + 1, nums + n + 1) - (nums + 1);
	for (int i = 1; i <= maxn; ++ i)
		for (int j = nums[i]; j <= nums[n]; j += nums[i])
			ans = max(ans, nums[lower_bound(nums + 1, nums + 2 + n, j + nums[i]) - nums - 1] - j);
	output(ans);
	return 0;
}
