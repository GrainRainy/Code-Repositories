#include <bits/stdc++.h>
using namespace std;

long long  a[20][20];

int main()
{
	int n;
	while (cin >> n, n)
	{
		for (int i = 0; i < n; i ++)
		{
			for (int j = 0; j < n; j ++)
			{
				a[i][j] = pow(2, i + j);
				printf("%lld ",a[i][j]);
				// or cout << fixed << setprecision(0) a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;			
	}
	return 0;
}
