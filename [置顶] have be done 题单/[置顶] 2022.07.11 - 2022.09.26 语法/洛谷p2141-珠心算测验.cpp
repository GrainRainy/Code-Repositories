#include <bits/stdc++.h>

using namespace std;

bool flag[110];
int a[110];

bool search(int n, int sum, int a[110], bool flag[110])
{
	for (int i = 0; i < n; i ++)
		if (sum == a[i] && !flag[i])
		{
			flag[i] = 1;
			return 1;
		}
	return 0;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
		
	int cnt = 0;
	for (int i = 0; i < n - 1; i ++)
		for (int j = i + 1; j < n; j ++)
			if (search(n, a[i] + a[j], a, flag)) cnt ++;
	cout << cnt << endl;
	return 0;
}
