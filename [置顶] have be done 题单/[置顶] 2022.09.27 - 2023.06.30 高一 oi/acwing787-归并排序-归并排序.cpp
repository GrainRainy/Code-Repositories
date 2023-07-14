#include <iostream>
using namespace std;

const int N = 1000010;
int n;
int q[N], ans[N];

void merge_sort(int q[], int l, int r)
{
	if (l >= r) return;
	
	int mid = l + r >> 1;
	merge_sort (q, l, mid);
	merge_sort (q, mid + 1, r);
	
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
		if (q[i] <= q[j]) ans[k ++] = q[i ++];
		else ans[k ++] = q[j ++];
		
	while (i <= mid) ans[k ++] = q[i ++];
	while (j <= r) ans[k ++] = q[j ++];
	
	for (int i = l, j = 0; i <= r; i ++, j ++) q[i] = ans[j];
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%d" ,&q[i]);
	
	merge_sort(q, 0, n - 1);
	
	for (int i = 0; i < n; i ++) printf("%d", q[i]);
	return 0;
}
