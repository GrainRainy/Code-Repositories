#include <bits/stdc++.h>
using namespace std;

double d1, c, d2, p;
int n;
double cost;

struct station
{
	double dis, pri;
	
	bool operator < (const station &t) const
	{
		return dis < t.dis;
	}
}sta[10];

void solve(int idx)
{
	if (idx == n + 1) return;
	int minidx = idx;
	double minpri = sta[idx].pri;
	int maxidx = idx;
	for (int i = idx + 1; sta[i].dis - sta[idx].dis <= c * d2 && i <= n + 1; i ++)
	{
		maxidx = i;
		if (sta[i].pri < minpri) minidx = i, minpri = sta[i].pri;
	}
	// find the next point to be stay
	
	if (minidx == idx && minpri == sta[idx].pri)
	{
		cost += sta[idx].pri * (sta[maxidx].dis - sta[idx].dis) / d2;
		solve(maxidx);
		return;
	}
	// else
	cost += sta[idx].pri * (sta[minidx].dis - sta[idx].dis) / d2;
	solve(minidx);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> d1 >> c >> d2 >> p >> n;
	
	sta[0].dis = 0, sta[0].pri = p;
	for (int i = 1; i <= n + 1; i ++)
	{
		if (i == n + 1) sta[i].dis = d1, sta[i].pri = 0x3f3f3f3f;
		else cin >> sta[i].dis >> sta[i].pri;
		if (c * d2 < sta[i].dis - sta[i - 1].dis)
		{
			puts("No Solution");
			return 0;
		}
	}
	
	sort (sta, sta + n + 2);
	
	solve(0);
	
	printf("%.2lf\n", cost);
	
	return 0;
}
