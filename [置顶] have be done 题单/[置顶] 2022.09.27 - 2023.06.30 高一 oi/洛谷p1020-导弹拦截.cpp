#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5;

int bomb[N];
int dp[N];
// total

int q[N];
// task1



// task2

int main()
{
	int tmp, n;
	for (int i = 1; ~scanf("%d", &tmp); i ++)
		bomb[i] = tmp, n = i;
	// n refer to the number of bombs
	
	int len = 0;
	q[0] = -2e9;
	for (int i = 1; i <= n; i ++)
	{
		int l = 0, r = len;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (q[mid] >= bomb[i]) l = mid;
			else r = mid - 1;
		}
		
		len = max(len, r + 1);
		q[r + 1] = bomb[i];
	}
	
	cout << len << endl;
	// 第一问：最长不降子序列 
	
	memset(q, 0, sizeof q);
	len = 0;
	
	q[0] = -2e9;
	for (int i = 1; i <= n; i ++)
	{
		int l = 0, r = len;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (q[mid] < bomb[i]) l = mid;
			else r = mid - 1;
		}
		
		len = max(len, r + 1);
		q[r + 1] = bomb[i];
	}
	cout << len << endl;
	
	// 第二问：最长上升子序列 Dilworth  
	return 0;
}
