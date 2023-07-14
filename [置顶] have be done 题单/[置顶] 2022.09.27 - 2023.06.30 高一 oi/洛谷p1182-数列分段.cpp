#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int maxn, sum;
int nums[N];

bool check(int sum)
{
	int tmpsum = 0, maxsum = sum, cnt = 0;
	for (int i = 0; i < n; i ++)
	{
		if (tmpsum + nums[i] > maxsum) cnt ++, tmpsum = nums[i];
		else tmpsum += nums[i];
	}
	if (cnt >= m) return true;
	return false;
}

int bsearch(int l, int r)
{
	int mid;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
	{
		cin >> nums[i];
		sum += nums[i], maxn = max(maxn, nums[i]);
	}
	// input
	cout << bsearch(maxn, sum) << endl;
	
	return 0;
}
