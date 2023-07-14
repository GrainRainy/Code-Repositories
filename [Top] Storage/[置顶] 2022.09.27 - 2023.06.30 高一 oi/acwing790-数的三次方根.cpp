#include <iostream>

using namespace std;

int main()
{
	double n;
	double l = -10000, r = 10000;
	cin >> n;
	while (r - l > 1e-8)
	{
		double mid = (l + r) / 2;
		if (mid * mid * mid >= n) r = mid;
		else l = mid;
	}
	printf("%.6llf\n", l);
	return 0;
}
