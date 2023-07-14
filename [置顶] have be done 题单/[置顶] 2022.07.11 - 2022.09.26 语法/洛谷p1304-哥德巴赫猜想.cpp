#include <bits/stdc++.h>
using namespace std;

bool prime(int n)
{
	for (int i = 2; i <= sqrt(n); i ++)
		if (n % i == 0) return 0;
	return 1;
}

int main()
{
	int n;
	cin >> n; 
	for (int i = 4; i <= n; i += 2)
	{
		for (int j = 2; j <= n; j ++)
		{
			if (prime(j) && prime(i - j))
			{
				//cout << i << "=" << j << "+" << i - j << endl;
				printf("%d=%d+%d\n", i, j, i - j);
				break;
			}
		}
	}
	return 0;
}
