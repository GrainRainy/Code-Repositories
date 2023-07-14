#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 10;

struct gap
{
	int a, b;
	
	bool operator < (const gap &t) const
	{
		return a < t.a;
	}
	
}nums[N];

int n;
int q[N];

int LIS()
{
	q[0] = -2e5;
	int len = 0;
	for (int i = 0; i < n; i ++)
	{
		int l = 0, r = len;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (q[mid] <= nums[i].b) l = mid;
			else r = mid - 1;
		}
		q[r + 1] = nums[i].b;
		len = max(len, r + 1);
	}
	return len;
}

signed main()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> nums[i].a >> nums[i].b;
	// input
	
	sort(nums, nums + n);
	
	cout << LIS() << endl;
	
	return 0;
}
