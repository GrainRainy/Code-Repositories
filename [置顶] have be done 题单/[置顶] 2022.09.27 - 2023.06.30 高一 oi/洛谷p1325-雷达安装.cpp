#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;

struct range
{
	double l, r;
	
	bool operator < (const range &t) const
	{
		if (r != t.r) return r < t.r;
		else return l > t.l;
	}
}nums[N];

int ans;

int main()
{
	int n, d;
	cin >> n >> d;
	int x, y;
	for (int i = 1; i <= n; i ++)
	{
		cin >> x >> y;
		if (y <= d)
		{
			nums[i].l = x - sqrt(d * d - y * y);
			nums[i].r = x + sqrt(d * d - y * y);
		}
		else
		{
			puts("-1");
			return 0;
		}
	}
	
	sort(nums + 1, nums + n + 1);
	// input
	
	int tmpr = nums[1].r;
	ans = 1;
	for (int i = 2; i <= n; i ++)
		if (nums[i].l > tmpr)
			tmpr = nums[i].r, ans ++;
	
	cout << ans << endl;
	
	return 0;
}
