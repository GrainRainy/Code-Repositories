#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n;
int nums[N];
int f[N][3];
// 0 refers to 有
// 1 指无第一天
// 2 指无第二天 (可以买入) 

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> nums[i];
	// input
	
	f[0][1] = f[0][0] = 0xcfcfcfcf;
	f[0][2] = 0;
	// init
	
	for (int i = 1; i <= n; i ++)
	{
		f[i][0] = max(f[i - 1][0], f[i - 1][2] - nums[i]);
		f[i][1] = f[i - 1][0] + nums[i];
		f[i][2] = max(f[i - 1][1], f[i - 1][2]);
	}
	// dp
	
	cout << max(f[n][1], f[n][2]) << endl;
	return 0;
}
