#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct ticket
{
	int prc;
	int tm;
	bool be_used;
}tps[N];

int hh = 0, tt = 0;
// refers to the beginning of quans
int cst;
// total cost

int main()
{
	
	// freopen("P5661_7.in", "r", stdin);
	// freopen("out.out", "w", stdout);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		int type, price, tim;
		cin >> type >> price >> tim;
		// input
		if (!type)
		// subway
		{
			cst += price;
			tps[tt].prc = price;
			tps[tt ++].tm = tim;
		}
		// subway done !!!
		else
		{
			while (hh < tt && tim - tps[hh].tm > 45) hh ++;
			bool flags = false;
			for (int j = hh; j < tt; j ++)
			// search from the head
				if (price <= tps[j].prc && !tps[j].be_used)
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
	
	// fclose(stdin);
	// fclose(stdout);
	
	return 0;
}
