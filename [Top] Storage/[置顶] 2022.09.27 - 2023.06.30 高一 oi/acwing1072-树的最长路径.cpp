#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = N << 1;
// 由于存储无向边，需要开两倍空间存储 

int h[N], idx;
struct node
{
	int to, nxt, w;
}edge[M];

int n, ans;

void add(int a, int b, int c)
{
	edge[++ idx].to = b;
	// start to save from 1
	edge[idx].w = c;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

int dfs(int u, int father)
// 返回从当前点向下搜索的最大长度  
// fahter 防止 dfs 反向搜索
{
	int dist = 0;
	int d1 = 0, d2 = 0;
	// 表示以当前节点为起始位置，向下搜索的最长距离与次长距离 
	
	for (int i = h[u]; i != -1; i = edge[i].nxt)
	{
		int j = edge[i].to;
		if (j == father) continue;
		int d = dfs(j, u) + edge[i].w;
		dist = max(dist, d);
		
		if (d >= d1) d2 = d1, d1 = d;
		else if (d > d2) d2 = d;
		// 对最大值和次大值进行维护 
	}
	ans = max(ans, d1 + d2);
	return dist;
}

int main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	 
	for (int i = 0; i < n - 1; i ++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
	}
	
	dfs(1, -1);
	
	cout << ans << endl;
	
	return 0;
}
