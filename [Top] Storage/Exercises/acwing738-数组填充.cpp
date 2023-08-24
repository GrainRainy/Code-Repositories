#include <bits/stdc++.h>
using namespace std;
int main()
{
	int v;
	cin >> v;
	int a[15] = {v};
	for (int i = 1;i <= 10;i ++)
	{
		a[i] = a[i - 1] * 2;
	}
	for (int i = 0;i < 10;i ++)
	{
		printf("N[%d] = %d\n",i,a[i]);
	}
	return 0;
}
