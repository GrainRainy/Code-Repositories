#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int cntt = 0,cntc = 0,cntr = 0,cntf = 0;
	int x;
	char y;
	for (int i = 1;i <= n;i ++)
	{
		cin >> x >> y;
		if (y == 'C')
		{
			cntt += x;
			cntc += x;
		}
		else if (y == 'R')
		{
			cntt += x;
			cntr += x;
		}
		else 
		{
			cntt += x;
			cntf += x;
		}
	}
	
	printf("Total: %d animals\n",cntt);
	printf("Total coneys: %d\n",cntc);
	printf("Total rats: %d\n",cntr);
	printf("Total frogs: %d\n",cntf);
	printf("Percentage of coneys: %.2lf %%\n",cntc * 1.0 / cntt * 100);
	printf("Percentage of rats: %.2lf %%\n",cntr * 1.0 / cntt * 100);
	printf("Percentage of frogs: %.2lf %%\n",cntf * 1.0 / cntt * 100);
	return 0;
}
