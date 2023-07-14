#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

typedef unsigned long long ULL;

int t;
ULL bx, by, ax, ay, cx, cy, r;
double mind, maxd;

double get_dist(int a, int b, int c, int d)
{
	double dist = sqrt((ULL)(a - c) * (a - c) + (ULL)(b - d) * (b - d));
	return dist;
}

double cz()
{
	double x = get_dist(bx, by, cx, cy) * get_dist(bx, by, cx, cy);
	x -= get_dist(ax, ay, cx, cy) * get_dist(ax, ay, cx, cy);
	x += get_dist(ax, ay, bx, by) * get_dist(ax, ay, bx, by);
	x /= 2 * get_dist(ax, ay, bx, by);
	
	double ans = sqrt(get_dist(bx, by, cx, cy) * get_dist(bx, by, cx, cy) - x * x);
	return ans;
}

int main()
{
	input(t);
	while (t --)
	{
		input(ax), input(ay), input(bx), input(by);
		input(cx), input(cy), input(r);
		
		mind = cz();
		maxd = max(get_dist(ax, ay, cx, cy), get_dist(bx, by, cx, cy));
		printf("%.2lf %.2lf\n", mind - r, maxd + r);
	}
	return 0;
}
