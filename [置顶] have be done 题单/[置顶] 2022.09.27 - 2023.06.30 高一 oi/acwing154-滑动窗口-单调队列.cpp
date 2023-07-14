#include <iostream>

using namespace std;

const int N = 1e6;
int nums[N], q[N];

int main()
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i ++)
		cin >> nums[i];
	
	int hh = 0, tt = -1;
	for (int i = 0; i < n; i ++)
	{
		if (hh <= tt && i - k + 1 > q[hh]) hh ++;
		//判断队头是否滑出窗口 
		while (hh <= tt && nums[q[tt]] >= nums[i]) tt --;
		// 对队列进行严格单调性处理 
		q[++ tt] = i;
		// 读入队列 
		if (i >= k - 1) cout << nums[q[hh]] << ' ';
		// 判断 i 是否小于区间长度，如果是则跳过 
	}
	cout << endl;
	// 最小值
	
	hh = 0, tt = -1;
	for (int i = 0; i < n; i ++)
	{
		if (hh <= tt && i - k + 1 > q[hh]) hh ++;
		//判断队头是否滑出窗口 
		while (hh <= tt && nums[q[tt]] <= nums[i]) tt --;
		// 对队列进行单调性处理 
		q[++ tt] = i;
		// 读入队列 
		if (i >= k - 1) cout << nums[q[hh]] << ' ';
		// 判断 i 是否小于区间长度，如果是则跳过 
	}
	cout << endl;
	// 最大值 
}
