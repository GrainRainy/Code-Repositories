#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;

int rope[N];
int n, k;

bool check(int x)
{
	int ans = 0;
	for (int i = 0; i < n; i ++)
		ans += rope[i] / x;
	if (ans >= k) return true;
	return false;
}

int bsearch(int l, int r)
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

	cin >> n >> k;
	for (int i = 0; i < n ; i ++)
	{
		double tmp;
		cin >> tmp;
		rope[i] = tmp * 100;
	}
	// input
	sort(rope, rope + n);
	
	printf("%.2lf\n", bsearch(1, rope[n - 1]) * 1.0 / 100);
	return 0;
}
