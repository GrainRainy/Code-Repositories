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

const int N = 1e5;
int n, mod;
int nums[N], idx;
int ans = 0;

int main()
{
	input(n), input(mod);
	for (int i = 1; i <= n; i ++)
	{
		int a, b;
		input(a), input(b);
		while (a --) nums[++ idx] = b % mod;
	}
	
	sort(nums + 1, nums + idx + 1);
	
	for (int i = 1; i <= idx; i ++)
	{
		if (nums[i] == -1) continue;
		int j = idx;
		while (nums[j] == -1 or nums[i] + nums[j] > mod) j --;
		ans += mod - (nums[i] + nums[j]) % mod;
		nums[i] = nums[j] = -1;
	}
	cout << ans << endl;
	
	return 0;
}

