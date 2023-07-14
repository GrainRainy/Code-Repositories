#include <iostream>

using namespace std;

int nums[1010];
long long cnt;

int main()
{
	int n, x;
	cin >> n >> x;
	 
	for (int i = 1; i <= n; i ++)
	{
		cin >> nums[i];
		if (nums[i - 1] + nums[i] > x)
		{
			cnt += nums[i - 1] + nums[i] - x;
			nums[i] =  x - nums[i - 1];
		}
	}
	cout << cnt << endl;
	return 0;
}
