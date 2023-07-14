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

const int N = 2e5 + 10;
int n;
int nums[N];

int main()
{
	input(n);
	for (int i = 1; i <= n; ++ i)
		input(nums[i]);
	int ans = -1, ans_idx = -1;
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
		{
			if (nums[i] == nums[j]) continue;
			int tmp = max(nums[i], nums[j]) % min(nums[i], nums[j]);
			if (!tmp) continue;
			if (abs(nums[tmp] - nums[1]) > ans)
			{
				ans_idx = tmp;
				ans = abs(nums[tmp] - nums[1]);
			}
		}
	cout << ans_idx << endl;
	return 0;
}
