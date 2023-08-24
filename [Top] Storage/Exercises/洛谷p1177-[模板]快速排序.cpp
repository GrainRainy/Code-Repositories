#include <iostream>

using namespace std;

const int N = 1e5;
int a[N + 10];

void quick_sort(int a[], int l, int r)
{
	if (l >= r) return;
	int i = l - 1, j = r + 1;
	int x = a[(l + r)/ 2];
	while (i < j)
	{
		do i ++; while (a[i] < x);
		do j --; while (a[j] > x);
		if (i < j) swap(a[i], a[j]);
	}
	quick_sort(a, l ,j);
	quick_sort(a, j + 1, r);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	
	quick_sort(a, 0, n - 1);
	
	for (int i = 0; i < n; i ++)
		cout << a[i] << ' ';
	
	cout << endl;
	return 0;
}
