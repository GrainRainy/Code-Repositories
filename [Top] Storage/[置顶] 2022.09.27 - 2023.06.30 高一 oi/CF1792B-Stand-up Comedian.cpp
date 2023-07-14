#include <bits/stdc++.h>

using namespace std;

int nums[5];

int solve()
{
	int ans = 0;
	for (int i = 1; i <= 4; i ++)
		cin >> nums[i];
    ans += nums[1];
    if(! ans) return min(1, nums[2] + nums[3] + nums[4]);
    if(nums[2] > nums[3]) swap(nums[2], nums[3]);
    ans += nums[2] << 1;
    return min(ans + nums[1] + 1, ans + nums[3] - nums[2] + nums[4]);
}

int main()
{
	int t;
	cin >> t;
	while (t --)
		cout << solve() << endl;
	return 0;
}
