#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int nums[N];

int main()
{
	LL n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> nums[i];
	
	sort (nums, nums + n);
	
	LL tmp = nums[0];
	LL tmpsum = -1;
	for (int i = 1; i < n; i ++)
	{
		if ((n - i) * nums[i] > tmpsum)
			tmpsum = (n - i) * nums[i], tmp = nums[i];
	}
	cout << tmpsum << " " << tmp << endl;
	return 0;
}
