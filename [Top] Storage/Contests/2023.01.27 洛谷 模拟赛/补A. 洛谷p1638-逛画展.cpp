#include <iostream>

using namespace std;

const int N = 1e6 + 10, M = 2e3 + 10;

int st[M], nums[N];

int n, m;
int tmpcnt;
int hh = 1, tt = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> nums[i];
	for (int i = 1; i <= n; i ++)
	{
		if (!st[nums[i]]) tmpcnt ++;
		st[nums[i]] ++;
		if (tmpcnt == m)
		{
			tt = i;
			break;
		}
	}
	while (st[nums[hh]] > 1) st[nums[hh ++]] --;
	int anslen = tt - hh + 1, ansl = hh, ansr = tt;
	for (int i = tt; i <= n; i ++)
	{
		tt ++;
		st[nums[tt]] ++;
		while (st[nums[hh]] > 1) st[nums[hh ++]] --;
		if (anslen > tt - hh + 1)
			anslen = tt - hh + 1, ansl = hh, ansr = tt; 
	}
	cout << ansl << " " << ansr << endl;
	return 0; 
}
