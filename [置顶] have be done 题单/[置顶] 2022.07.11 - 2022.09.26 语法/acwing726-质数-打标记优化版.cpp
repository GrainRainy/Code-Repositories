#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n --)
	{
		int x;
		cin >> x;
		bool flag = 1;
		int i;
		for (i = 2;i <= sqrt(x);i ++)
		{
			if (x % i == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag) printf("%d is prime\n",x);
		else printf("%d is not prime\n",x);
	}
	return 0;
}
