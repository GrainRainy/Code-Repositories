#include <bits/stdc++.h>
using namespace std;
int main()
{
	for (int i = 0;i < 100;i ++)
	{
		double x;
		cin >> x;
		if (x <= 10)
			printf("A[%d] = %.1lf\n",i,x);
	}
	return 0;
}
