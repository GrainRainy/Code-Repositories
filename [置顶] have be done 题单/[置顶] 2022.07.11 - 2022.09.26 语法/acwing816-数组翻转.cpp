#include <bits/stdc++.h>
using namespace std;

int a[1005];

void fanzhuan(int a[], int size)
{
	for (int i = 1, j = size;i != j && i - 1 != j; i ++, j --)
		swap(a[i], a[j]);
}

int main()
{
	int n, size;
	cin >> n >> size;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	fanzhuan(a, size);
	for (int i = 1; i <= n; i ++)
		cout << a[i] << " ";
	return 0;
}
