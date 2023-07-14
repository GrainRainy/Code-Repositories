#include <bits/stdc++.h>
using namespace std;

int a[10];
bool be[10];
int n;

void dfs(int wei, int a[], bool be[])
{
	if (wei > n)
	{
		for (int i = 1; i <= n; i ++) cout << a[i] << " ";
		cout << endl;
	}
	else 
	{
		for (int i = 1; i <= n; i ++)
		{
			if (!be[i])
			{
				be[i] = 1;
				a[wei] = i;
				dfs(wei + 1, a, be);
				a[wei] = be[i] = 0;
			}
		}
	}
}

int main()
{
	cin >> n;
	dfs(1, a, be);
	return 0;
}
