#include <iostream>

using namespace std;

int cnt_one(int x)
{
	int ans = 0;
	while (x)
	{
		if (x & 1) ans ++;
		x >>= 1;
	}
	return ans;
}

int main()
{
	int n, k;
	cin >> n >> k;
	// input
	int over = cnt_one(n) - k;
	int need = 0;
	if (over > 0)
	{
		int base = 1;
		while (over > 0)
		{
			if (n & 1) need += base, n ++;
			n >>= 1;
			base *= 2;
			over = cnt_one(n) - k;
		}
		cout << need << endl;
	}
	else cout << 0 << endl;
}
