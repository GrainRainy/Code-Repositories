#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int nums[N], q[N];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> nums[i];
	
	int len = 0;
	q[0] = -2e9;
	for (int i = 0; i < n; i ++)
	{
		int l = 0, r = len;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (q[mid] < nums[i]) l = mid;
			else r = mid - 1;
		}
		len = max(len, r + 1);
		q[r + 1] = nums[i];
	}
	cout << len << endl;
	return 0;
}
