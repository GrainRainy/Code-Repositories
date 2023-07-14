#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int n, m;
pair<int, int> nums[N];

int getsum(int a)
{
	int tmpsum = 0;
	while (a != 0)
	{
		tmpsum += a % 10;
		a /= 10;
	}
	return tmpsum;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		nums[i].second = i;
	for (int i = 1; i <= n; i ++)
		nums[i].first = getsum(nums[i].second);
	sort(nums + 1, nums + n + 1);
	cout << nums[m].second << endl;
	return 0;
}
