#include <iostream>

using namespace std;

const int N = 1e6 + 10, M = 2e3 + 10;

int st[M], nums[N];

int n, m;
int hh = 1, tt = 1;

bool checkans()
{
	for (int i = 1; i <= m; i ++)
		if (!st[i]) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> nums[1];
	st[nums[1]] ++;
	if (tt - hh + 1 >= m && checkans())
	{
		cout << hh << " " << tt << endl;
		return 0;
	}
	
	for (int i = 2; i <= n; i ++)
	{
		cin >> nums[i];
		tt ++, st[nums[i]] ++;
		if (nums[tt] == nums[hh]) st[nums[hh]] --, hh ++;
		if (tt - hh + 1 >= m && checkans())
		{
			cout << hh << " " << tt << endl;
			return 0;
		}
	}
}
