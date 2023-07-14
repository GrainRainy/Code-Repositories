#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct ticket
{
	int prc;
	int tm;
	bool be_used;
}tps[N];

int idx;
// refers to the beginning of quans
int cst;
// total cost

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		int type, price, time;
		cin >> type >> price >> time;
		// input
		if (!type)
		// subway
		{
			tps[++ idx].prc = price, tps[idx].tm = time;
			tps[idx].be_used = false;
			cst += tps[idx].prc;
		}
		// subway done !!!
		else
		{
			bool flags = false;
			for (int j = 1; j <= idx; j ++)
			// search from the head
				if (time - tps[j].tm <= 45 && price <= tps[j].prc && !tps[j].be_used)
				{
					flags = true, tps[j].be_used = true;
					break;
				}
			// if quan can be used
			if (!flags) cst += price;
			// if quan can not be used
		}
	}
	cout << cst << endl;
	
	return 0;
}
