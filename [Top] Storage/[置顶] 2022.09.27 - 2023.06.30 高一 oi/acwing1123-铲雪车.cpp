#include <bits/stdc++.h>
using namespace std;
int main()
{
	double x1, y1, x2, y2, sum = 0;
	cin >> x1 >> y1;
	while (cin >> x1 >> y1 >> x2 >> y2)
		sum += sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) * 2;
	int time = round(sum / 1000 / 20 * 60);
	printf("%d:%02d\n", time / 60, time % 60);
}

