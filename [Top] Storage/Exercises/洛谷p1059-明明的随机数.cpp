#include <bits/stdc++.h>
using namespace std;

int a[105];
int b[1001];
int cnt;

int main()
{
	int n;
	cin >> n;
	int linshi;
	for (int i = 1; i <= n; i ++)
	{
		cin >> linshi;
		if (b[linshi] != 0) continue;
		else
		{
			cnt ++;
			b[linshi] ++;
			a[cnt] = linshi;
		}
	}
	n = cnt;//≤ª÷ÿ∏¥ ‰»Î 
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n - i; j ++)
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
	//≈≈–Ú
	
	cout << n << endl;
	for (int i = 1; i <= cnt; i ++)
		cout << a[i] << " " ;
	return 0; 
}
