#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main()
{
	int n;
	while(cin >> n, n)
	{
		for (int i = 0; i < n; i ++)
		{
			a[i][i] = 1;
			for (int j = i + 1; j < n; j ++)
			{
				a[i][j] = a[i][j - 1] + 1;
				a[j][i] = a[j - 1][i] + 1;
			}
		}
		
		for (int i = 0; i < n; i ++)
		{
			for (int j = 0; j < n;j ++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
