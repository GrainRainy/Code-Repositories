#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, c;
int cow[N];

bool check(int gap)
{
	int tmp = cow[0], res = n - c;
	for (int i = 1; i < n; i ++)
	{
		if (cow[i] - tmp < gap) res --;
		else tmp = cow[i];
		if (res < 0) return false;
	}
	return true;
}

int search(int l, int r)
{
	int ans;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i ++)
		cin >> cow[i];
	
	sort (cow, cow + n);
	
	cout << search(1, cow[n - 1]) << endl;
	
	return 0;
	
}
