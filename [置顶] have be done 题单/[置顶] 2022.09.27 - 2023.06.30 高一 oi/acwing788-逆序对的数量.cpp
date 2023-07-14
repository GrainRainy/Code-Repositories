#include <iostream>

using namespace std;

const int N = 100000;
int n;
int q[N + 10], tmp[N + 10];

long long merge_sort(int l ,int r)
{
	if (l >= r) return 0;
	int mid = l + r >> 1;
	long long res = merge_sort(l, mid) + merge_sort(mid + 1, r);
	
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
		if (q[i] <= q[j]) tmp[k ++] = q[i ++];
		else
		{
			tmp[k ++] = q[j ++];
			res += mid - i + 1;
		}
		
	while (i <= mid)
		tmp[k ++] = q[i ++];
	while (j <= r)
		tmp[k ++] = q[j ++];
		
	for (int i = l, j = 0;i <= r; i ++, j ++)
		q[i] = tmp[j];
		
	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> q[i];
	
	cout << merge_sort(0, n - 1) << endl;
	
	
	return 0;
}
