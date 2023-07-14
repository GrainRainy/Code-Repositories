#include <iostream>

using namespace std;

int t, n;
const int N = 60;
int nums[N];
int sum;
int op[N];

int main()
{
	cin >> t;
	while (t --)
	{
		cin >> n;
		for (int i = 0; i < n; i ++)
		{
			cin >> nums[i];
			sum += nums[i];
		}
		if (!(sum % 2))
		{
			cout << 0 << endl;
			continue;
		}
		int cnt = 114514;
		for (int i = 0; i < n; i ++)
		{
			int tmpcnt = 1;
			while ((nums[i] % 2) == ((nums[i] / 2) % 2))
			{
				tmpcnt ++;
				nums[i] /= 2;
				if (nums[i] == 0) break;
			}
			cnt = min(cnt, tmpcnt);
		}
		cout << cnt << endl;
		sum = 0;
	}
	return 0;
}
