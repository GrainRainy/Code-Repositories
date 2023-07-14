#include <bits/stdc++.h>
using namespace std;

int a[10005];
int cnt;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	
	for (int i = 1; i < n; i ++)
		for (int j = 1; j <= n - i; j ++)
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				cnt ++;
			}
	
	cout << cnt << endl;
	return 0;
}
