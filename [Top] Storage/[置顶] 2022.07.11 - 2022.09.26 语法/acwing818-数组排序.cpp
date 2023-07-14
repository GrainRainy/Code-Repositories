#include <bits/stdc++.h>

using namespace std;

void sort(int a[], int l, int r)
{
	for (int i = l; i <= r; i ++)
	{
		for (int j = i + 1; j <= r; j ++)
		{
			if (a[j] < a[i]) swap(a[i], a[j]);
		}
	}
}

int main()
{
	int a[1005];
	int n, l, r;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i ++) cin >> a[i];
	sort(a, l, r);
	for (int i = 0; i < n; i ++) cout << a[i] << " ";
	return 0;
}
