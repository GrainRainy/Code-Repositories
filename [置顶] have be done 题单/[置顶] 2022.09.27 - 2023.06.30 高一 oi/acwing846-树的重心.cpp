#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
const int M = N * 2;

int n, m, ans = N;
// ans 动态维护最小值 
int h[N], e[M], ne[M], idx;


bool st[N];

int dfs(int u)
// 返回以 u 为根节点的子子节点数量 
// u 表示当前搜索到的点 
{
	st[u] = true;
	// 更新搜索状态
	
	int sum = 1, res = 0;
	// sum 维护以 u 为根节点的子节点个数 
	// res 维护删掉 u 节点后各连通块中节点个数的最大值 
	for (int i = h[u]; i != -1; i = ne[i])
	// 遍历以 u 点作头节点的单链表 
	{
		int j = e[i];
		// 用于存储原图中连向的点 
		if (!st[j])
		// 如果该点没有被遍历过
		{
			int s = dfs(j);
			// 遍历该点
			// s 维护 u 所连通的 第 i 个子树的大小
			res = max(res, s);
			// 对当前节点的子树维护最大值 
			sum += s;
		}
	}
	
	res = max(res, n - sum);
	// 对除去该子树的其他树进行维护
	
	ans = min(ans, res);
	
	return sum; 
}

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

int main()
{
	memset(h, -1, sizeof h);
	
	cin >> n ;
	
	for (int i = 0; i < n - 1; i ++)
	// n 个数, n - 1 条边 
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	
	dfs(1);
	
	cout << ans << endl;
	
	return 0;
}
