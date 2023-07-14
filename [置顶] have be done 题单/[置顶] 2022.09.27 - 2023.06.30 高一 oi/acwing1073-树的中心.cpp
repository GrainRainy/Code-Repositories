#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = N << 1;
const int INF = 0x3f3f3f3f;

int h[N], idx;
struct node
{
	int to, nxt, w;
}edge[M];

int n;
int d1[N], d2[N];
// d1 表示从该点向下行进的最长距离
// d2 表示从该点向下行进的次长距离 
int up[N];
// up 表示从当前点向上行进的最长距离 
int p1[N], p2[N];
// 用于存储最长边和次长边由哪里转移而来 

void add(int a, int b, int c)
{
	edge[++ idx].to = b;
	edge[idx].w = c;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

int dfs_d(int u, int father)
// 求从 u 点向下走的最长路径 
{
	
	d1[u] = d2[u] = -INF;
	// 为对实数边权进行处理，初始值赋为负无穷
	for (int i = h[u]; i != -1; i = edge[i].nxt)
	{
		int j = edge[i].to;
		if (j == father) continue;
		// 如果该点是向上搜索的，那么直接跳过
		int d = dfs_d(j, u) + edge[i].w;
		// 取出向下的最长距离 
		if (d >= d1[u])
		{
			d2[u] = d1[u], d1[u] = d;
			p2[u] = p1[u], p1[u] = j;
		}
		else if (d > d2[u]) d2[u] = d, p2[u] = j;
	}
	
	if (d1[u] == -INF) d1[u] = d2[u] = 0;
	// 对于叶节点的特殊处理 
	
	return d1[u];
}

void dfs_u(int u, int father)
{
	for (int i = h[u]; i != -1; i = edge[i].nxt)
	{
		int j = edge[i].to;
		if (j == father) continue;
		
		if (p1[u] == j) up[j] = max(up[u], d2[u]) + edge[i].w;
		//  最长路径由该节点所在子树转移而来，则使用次大值 
		else up[j] = max(up[u], d1[u]) + edge[i].w;
		 
		dfs_u(j, u);
		
	}
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
	
	dfs_d(1, -1); // 向下搜索 
	dfs_u(1, -1);
	
	int res = INF;
	for (int i = 1; i <= n; i ++)
		res = min(res, max(d1[i], up[i]));
	cout << res << endl;
	
	return 0;
}
