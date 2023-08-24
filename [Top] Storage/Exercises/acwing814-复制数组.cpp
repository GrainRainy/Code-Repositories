#include <bits/stdc++.h>
using namespace std;

int a[105], b[105];

void copy(int a[], int b[], int size)
{
	for (int i = 0; i < size; i ++)
		b[i] = a[i];
	/* 
	或是使用：
	memcpy(b, a, size * 4);
	*/
}

int main()
{
	int n, m, size;
	cin >> n >> m >> size;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < m; i ++) cin >> b[i];
	copy(a, b, size);
	for (int i = 0; i < m; i ++) cout << b[i] << " ";
	return 0;
}
