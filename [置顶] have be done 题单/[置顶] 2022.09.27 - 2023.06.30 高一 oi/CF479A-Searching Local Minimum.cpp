#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10; 

int n;
int nums[N];

int get(int idx)
{
	if (nums[idx]) return nums[idx];
	cout << "? " << idx << endl; cout.flush();
	int tmp;
	cin >> tmp;
	nums[idx] = tmp;
	return tmp;
}

int main()
{
	cin >> n;
	nums[0] =nums[n + 1] = INT_MAX;
	int l = 1, r = n;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		int a = get(mid - 1), b = get(mid), c = get(mid + 1);
		if (a > b && b < c)
		{
			cout << "! " << mid << endl;
			return 0;
		}
		else if (a > b && b > c) l = mid;
		else r = mid - 1;
	}
	cout << "! " << l << endl;
	return 0;
}


