#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

struct segment
{
	int l, r;
	// refers to the left and the right head of each segment
	
	bool operator < (const segment &t) const
	{
		return r < t.r;
	}
	
}nums[N];

int cnt = 1;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> nums[i].l >> nums[i].r;
	
	sort(nums + 1, nums + n + 1);
	
	for (int i = 1; i <= n; i ++)
		cerr << nums[i].l << " " << nums[i].r << endl;

	int tmpl = nums[1].l, tmpr = nums[1].r;
	for (int i = 1; i <= n; i ++)
	{
		if (nums[i].l < tmpr) continue;
		else 
		{
			tmpl = nums[i].l, tmpr = nums[i].r;
			cnt ++;
		}
	}
	cout << cnt << endl;
	
	return 0;
	
}
