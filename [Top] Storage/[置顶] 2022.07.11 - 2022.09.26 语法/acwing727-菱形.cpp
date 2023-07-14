#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	
	int cx = (n + 1) / 2;
	int cy = (n + 1) / 2;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (abs(i - cx) + abs(j - cy) <= n / 2)
				cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
	return 0;
}
