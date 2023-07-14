#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], q[N];
// a[] 用于存储数列 
// p[] 用于维护所有不同长度的最长上升子序列结尾元素的最小值 

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	// input
	int len = 0;
	// 存储当前最长上升子序列的长度，即 q 数组中的元素个数 
	q[0] = -2e9;
	for (int i = 0; i < n; i ++)
	{
		int l = 0, r = len;
		while (l < r)
		{
			int mid = l + r  + 1 >> 1;
			if (q[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		// r 返回不大于 a[i] 的最长上升子序列尾元素的最大值 
		len = max(len, r + 1);
		q[r + 1] = a[i];
	}
	
	cout << len << endl;
	
	return 0;
}
