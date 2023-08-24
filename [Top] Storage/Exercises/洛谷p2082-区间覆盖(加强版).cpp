#include <iostream>
#include <algorithm>

typedef long long LL;

using namespace std;

const LL N = 1e5 + 10;

struct ababaab
{
	LL l, r;
	
	bool operator < (const ababaab &t) const
	{
		return l < t.l;
	}
	
}nums[N];

LL len = 0;

int main()
{
	LL n;
	cin >> n;
	for (LL i = 1; i <= n; i ++)
		cin >> nums[i].l >> nums[i].r;
	// input
	
	sort(nums + 1, nums + n + 1);
	
	LL tmpl = nums[1].l, tmpr = nums[1].r;
	len = tmpr - tmpl + 1;
	for (LL i = 2; i <= n; i ++)
	{
		if (nums[i].l <= tmpr && nums[i].r > tmpr)
		{
			len += nums[i].r - tmpr;
			tmpr = nums[i].r;
		}
		else if (nums[i].l > tmpr)
		{
			tmpl = nums[i].l, tmpr = nums[i].r;
			len += tmpr - tmpl + 1;
		}
	}
	cout << len << endl;
	
	return 0;
}
