#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, nums[N], cnt;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> nums[i];
	// input
	
	sort (nums, nums + n);
	
	while (n > 3)
	{
		cnt += min(nums[0] * 2 + nums[n - 1] + nums[n - 2], nums[0] + nums[1] * 2 + nums[n - 1]);
		n -= 2;
	}
	if (n == 1) cnt += nums[0];
	if (n == 2) cnt += max(nums[0], nums[1]);
	if (n == 3) cnt += nums[0] + nums[1] + nums[2];
	
	cout << cnt << endl;
	
	return 0;
}
