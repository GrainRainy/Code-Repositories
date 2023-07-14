#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;

int f[N], cnt = 1, be[N];
// be[] 表示当前位置是否有任务以及有多少个任务 
struct tasks
{
	int bg,tm;
	
	bool operator < (const tasks &a) const 
	{
		return bg > a.bg;
	}
	// 因为是从后向前扫，所以按照降序排列 
}tot[N];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i ++)
	{
		cin >> tot[i].bg >> tot[i].tm;
		be[tot[i].bg] ++;
	}
	// input
	
	sort(tot + 1, tot + k + 1);
	
	for (int i = n; i >= 1; i --)
	{
		if (!be[i]) f[i] = f[i + 1] + 1;
		else
			for (int j = 1; j <= be[i]; j ++)
			{
				f[i] = max(f[i], f[i + tot[cnt].tm]);
				// cnt 作为计数器判断当前遍历到哪个任务 
				cnt ++;
			}
	}
	
	cout << f[1] << endl;
	// 因为是从后往前遍历，所以输出 f[1] 即可 
	
	return 0;
}
