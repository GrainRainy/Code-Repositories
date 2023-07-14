#include <bits/stdc++.h>

using namespace std;

double d(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
	double x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	printf("%.2lf\n", d(x1, y1, x2, y2) + d(x2, y2, x3, y3) + d(x3, y3, x1, y1));
	return 0;
}
