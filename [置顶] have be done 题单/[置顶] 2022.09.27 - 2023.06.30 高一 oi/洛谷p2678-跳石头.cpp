#include <iostream>
using namespace std;
const int N = 50010;

int d, n, m;
int nums[N];

bool check(int gap)
{
	int cnt = 0;
	int tmp = 0;
	for (int i = 1; i <= n + 1; i ++)
	{
		if (nums[i] - tmp < gap) cnt ++;
		else tmp = nums[i];
		if (cnt > m) return false;
	}
	
	return true;
}

int main()
{
	cin >> d >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> nums[i];
	nums[n + 1] = d;
	// input
	
	int l = 1, r = d, ans = 0;
	while (l < r)
	{
		int mid = l + r + 1>> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	
	cout << l z<< endl;

	
	return 0;
}
