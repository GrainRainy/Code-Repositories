#include <bits/stdc++.h>
using namespace std;

const double pai = 3.14159265;

int main()
{
	double h, r;
	cin >> h >> r;
	double one = pai * r * r * h;
	int ans;
	ans = ceil(20000 / one);
	cout << ans << endl;
	return 0;
}
