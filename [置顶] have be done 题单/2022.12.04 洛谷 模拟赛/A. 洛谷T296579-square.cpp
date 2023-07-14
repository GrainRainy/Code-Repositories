#include <bits/stdc++.h>

using namespace std;

double ans[3];
int idx;
// the next person

int main()
{
	double n, k;
	cin >> n >> k;
	idx = 0;
	while (k --)
	{
		for (int i = 1; i <= 4; i ++)
			ans[idx ++] += n, idx %= 3;
		n = (n * 1.0 / 2) * sqrt(2);
	}
	
	for (int i = 0; i <= 2; i ++)
		printf("%.3lf ", ans[i]);
	
	
	return 0;
}
