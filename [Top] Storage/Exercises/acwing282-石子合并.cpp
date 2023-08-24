#include <iostream>

using namespace std;

const int N = 310;
const int INF = 1e8;

int n;
int s[N], f[N][N];
// s 存储前缀和
 
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> s[i];
	// input
	for (int i = 2; i <= n; i ++) s[i] += s[i - 1];
	// 处理前缀和
	
	for (int len = 2; len <= n; len ++)
	// 枚举待合并的区间长度
		for (int i = 1; i + len - 1 <= n; i ++)
		// 枚举区间长度 
		{
			int l = i, r = i + len - 1;
			//  取出起始位置 
			f[l][r] = INF;
			// 初始化一个最大值，循环找出最小值 
			for (int k = l; k < r; k ++)
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
				// 按合并区间的分界线分类枚举 
		}
	cout << f[1][n] << endl;
	
	return 0; 
	
}
