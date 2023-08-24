#include <bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
	for (int i = 1;i <= 10;i ++)
	{
		cin >> a[i];
		if (a[i] <= 0) n = 1;
		a[i] = n;
	}
	for (int i = 1;i <= 10;i ++)
	{
		printf("X[%d] = %d\n",i - 1,a[i]);
	}
	return 0;
}
