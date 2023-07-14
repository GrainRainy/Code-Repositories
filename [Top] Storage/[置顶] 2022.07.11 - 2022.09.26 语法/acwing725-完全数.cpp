#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i ++)
	{
		int sum = 0;
		int a;
		cin >> a;
		if (a == 1)
		{
			printf("%d is not perfect\n",a);
			continue;
		}
		for (int j = 1;j <= sqrt(a);j ++)
		{
			if (a % j == 0) sum += j + a / j;
		}
		if (sum - a == a) printf("%d is perfect\n",a);
		else printf("%d is not perfect\n",a);
	}
	return 0;
}
