#include <iostream>
#include <cmath>
#include <algorithm>

typedef long long LL;

using namespace std;

const LL N = 1e5 + 10, INF = 1e9;

LL sch[N];
LL angry;
LL nsc, nst, scr;

LL upper_min(LL x)
{
	LL l = 1, r = nsc, mid;
	while (l < r)
	{
		mid = l + r >> 1;
		if (sch[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}

LL lower_max(LL x)
{
	LL l = 1, r = nsc, mid;
	while(l < r)
	{
		mid = l + r + 1 >> 1;
		if (sch[mid] <= x) l = mid;
		else r = mid - 1;
	}
	return l;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> nsc >> nst;
	for (LL i = 1; i <= nsc; i ++)
		cin >> sch[i];
	
	sort(sch + 1, sch + nsc + 1);
	
	for (LL i = 1; i <= nst; i ++)
	{
		cin >> scr;
		
		// cerr << angry << " ";
		
		if (scr < sch[1]) angry += sch[1] - scr;
		else if (scr > sch[nsc]) angry += scr - sch[nsc];
		else angry += min(sch[upper_min(scr)] - scr, scr - sch[lower_max(scr)]);
		
		cerr << angry << endl;
	}
	
	cout << angry << endl;
	return 0;
}
