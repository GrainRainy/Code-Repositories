#include <bits/stdc++.h>
using namespace std;

int a[1000];

void print(int a[], int size)
{
	for (int i = 0; i < size; i ++)
	{
		cout << a[i] << " ";
	}
	
}

int main()
{
	int n, size;
	cin >> n >> size;
	for (int i = 0; i < n;i ++)
		cin >> a[i];
	print(a, size);
	return 0;
}
