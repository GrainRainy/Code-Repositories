#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

const int N = 3000;

struct cow
{
	int l, r;
	bool used = 0;
	
	bool operator < (const cow &t) const
	{
		return l < t.l;
	}
}cows[N];

struct tmpcow
{
	int l, r;
	int number;
	
	bool operator < (const tmpcow &t) const
	{
		return r < t.r;
	}
}tmpcows[N];

struct lotion
{
	int val, num;
	
	bool operator < (const lotion &t) const
	{
		return val < t.val;
	}
}lts[N];

int C, L;
int cnt;

int main()
{
	cin >> C >> L;
	for (int i = 1; i <= C; i ++)
		cin >> cows[i].l >> cows[i].r;
	for (int i = 1; i <= L; i ++)
		cin >> lts[i].val >> lts[i].num;
		
	sort(cows + 1, cows + C + 1);
	sort(lts + 1, lts + L + 1);
	// input
	
	for (int i = 1; i <= L; i ++)
	{
		int tmpnums = 0;
		
		for (int j = 1; j <= C; j ++)
		{
			// cerr << j << endl;
			// cout << cows[j].l << " " << lts[i].val << " " << cows[j].r << " " << cows[j].used << endl;
			if (cows[j].l <= lts[i].val && cows[j].r >= lts[i].val && !cows[j].used)
			{
				tmpcows[++ tmpnums].l = cows[j].l;
				tmpcows[tmpnums].r = cows[j].r;
				tmpcows[tmpnums].number = j;
			}
		}
		
		sort(tmpcows + 1, tmpcows + tmpnums + 1);

		if (tmpnums < lts[i].num)
		{
			for (int k = 1; k <= tmpnums; k ++)
				cows[tmpcows[k].number].used = 1;
			cnt += tmpnums;
		}
		else
		{
			for (int k = 1; k <= lts[i].num; k ++)
				cows[tmpcows[k].number].used = 1;
			cnt += lts[i].num;
		}
			
		tmpnums = 0;
	}
	
	cout << cnt << endl;
	
	return 0;
}

/*
3 2
1 6
2 3
3 4
3 1
5 1

*/
