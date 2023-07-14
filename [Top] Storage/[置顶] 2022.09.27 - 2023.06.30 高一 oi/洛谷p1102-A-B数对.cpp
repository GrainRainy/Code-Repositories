#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

LL nums[N], cnt[N];
LL ans;
int n, c;

int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i ++)
		cin >> nums[i];
	sort(nums, nums + n);
	// input
	for (int i = 0; i < n; i ++)
		ans += upper_bound(nums, nums + n, nums[i] - c) - lower_bound(nums, nums + n, nums[i] - c);
	cout << ans << endl;
}
