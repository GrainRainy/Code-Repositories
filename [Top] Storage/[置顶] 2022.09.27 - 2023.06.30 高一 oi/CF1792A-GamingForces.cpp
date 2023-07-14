#include <bits/stdc++.h>

using namespace std;

const int N =110;

int nums[N];

int solve()
{
	int n;
	cin >> n;
	if (n == 0) return 0;
	for (int i = 1; i <= n; i ++)
	{
		cin >> nums[i];
		if (nums[i] == 0) i --, n --;
	}
		
	// input
	sort(nums + 1, nums + n + 1);
	int idx = 1;
	while (nums[idx] == 1) idx ++;
	idx --;
	int ans = ceil(idx * 1.0 / 2) + n - idx;
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t --) cout << solve() << endl;
	return 0;
}
