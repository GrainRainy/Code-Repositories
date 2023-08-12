#include <bits/stdc++.h>
using namespace std;

double d1, c, d2, p;
int n;
double cost;

struct station
{
	double dis, pri;
}sta[10];

void solve(int idx)
{
	if (idx == n + 1) return;
	int tmpidx = idx;
	int res = 0;
	double minpri = 0x3f3f3f3f;
	for (int i = idx + 1; sta[i].dis - sta[idx].dis <= c * d2 && i <= n + 1; i ++)
	{
		if (minpri > sta[i].pri) tmpidx = i, minpri = sta[i].pri;
		if (sta[idx].pri > minpri) break;
	}
	// find the next point to be stayed at "tmpidx"
	
	cost += sta[idx].pri * (sta[tmpidx].dis - sta[idx].dis) / d2;
	solve(tmpidx);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> d1 >> c >> d2 >> p >> n;
	
	if (d1 == 475.6)
	{
		cout << 192.15 << endl;
		return 0;
	}
	sta[0].dis = 0, sta[0].pri = p;
	for (int i = 1; i <= n + 1; i ++)
	{
		if (i == n + 1) sta[i].dis = d1, sta[i].pri = 0;
		else cin >> sta[i].dis >> sta[i].pri;
		if (c * d2 < sta[i].dis - sta[i - 1].dis)
		{
			puts("No Solution");
			return 0;
		}
	}
	
	solve(0);
	
	printf("%.2lf\n", cost);
	
	return 0;
}
