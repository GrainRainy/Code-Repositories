#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;

struct person
{
	int prc, val;
	// prc refers to the µ¥¼Û of milk
	// val refers to the Á¿ of milk
	
	bool operator < (const person &t) const
	{
		return prc < t.prc;
	}
	 
}nums[N]; 

int n, m;
int ans;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
		cin >> nums[i].prc >> nums[i].val;
	
	sort(nums + 1, nums + m + 1); 
	// input
	
	for (int i = 1; i <= m; i ++)
	{
		if (nums[i].val < n)
		{
			n -= nums[i].val;
			ans += nums[i].prc * nums[i].val;
		}
		else
		{
			ans += n * nums[i].prc;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
