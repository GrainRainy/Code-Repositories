#include <iostream>
#include <cstdio>

using namespace std;

const int N = 5000000;
int nums[N + 10];
int n, k;

void quick_sort(int nums[], int l ,int r)
{
	int mid = nums[l + r >> 1];
	int i = l;
	int j = r;
	
	do
	{
		while (nums[i] < mid) i ++;
		while (nums[j] > mid) j --;
		if (i <= j)
		{
			swap(nums[i], nums[j]);
			i ++;
			j --;
		}
	}	while (i <= j);
	
	if (i <= k) quick_sort(nums, i, r);
	else if (j >= k) quick_sort(nums, l, j);
	else
	{
		cout << nums[j + 1];
		exit(0);
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i ++)
		scanf("%d", &nums[i]);
		
	quick_sort(nums, 0, n - 1);
	
	
	return 0;
}
