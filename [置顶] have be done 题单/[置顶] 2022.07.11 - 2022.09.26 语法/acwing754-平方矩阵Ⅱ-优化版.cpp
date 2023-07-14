#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main()
{
	int n;
	while(cin >> n, n)
	{
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				a[i][j] = abs(i - j) + 1;
		
		for (int i = 0; i < n; i ++)
		{
			for (int j = 0; j < n; j ++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
