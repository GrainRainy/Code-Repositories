#include <bits/stdc++.h>

using namespace std;

int a[1000005];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	
	int cnt = 1;
	int cmp = -1;
	for (int i = 1; i <= n; i ++)
		if (a[i] > a[i - 1])  cnt ++;
		else
		{
			if (cnt > cmp) cmp = cnt;
			cnt = 1;
		}
		
	cout << cmp << endl;
	return 0;
}
