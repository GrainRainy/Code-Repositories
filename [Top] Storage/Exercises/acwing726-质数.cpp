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
		int i;
		for (i = 2;i <= sqrt(x);i ++)
		{
			if (x % i == 0)
			{
				printf("%d is not prime\n",x);
				break;
			}
		}
		if (x % i != 0 || x == 2) printf("%d is prime\n",x);
	}
	return 0;
}
