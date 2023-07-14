#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main()
{
	int n;
	while (cin >> n , n)
	{
		int c = ceil(n * 1.0/ 2);
		int cnt = 0;
		int num = 1;
		while (c --)
		{
			for (int i = cnt;i < n - cnt;i ++)
			{
				for (int j = cnt;j < n - cnt;j ++)
				{
					a[i][j] = num;
				}
			}
			cnt ++;
			num ++;
		}
		
		for (int i = 0;i < n;i ++)
		{
			for (int j = 0;j < n;j ++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;	
	}
	return 0;
}
