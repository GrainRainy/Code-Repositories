#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 10010;

int dist[N], last[N];

struct node{
	int a, b, w;
}edge[M];
// 表示从 a 到 b 有一条边权为 w 的边 

int n, m, k;

void bellman_ford()
{
	
	
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	for (int i = 0; i < k; i ++)
	{
		memcpy(last, dist, sizeof dist);
		// 备份 dist 数组，存储上一次迭代结果
		for (int j = 0; j < m; j ++)
		{
			int a = edge[j].a, b = edge[j].b, w = edge[j].w;
			dist[b] = min(dist[b], last[a] + w);
			// 使用上一次迭代结果更新，防止前面的结果影响后面 
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i ++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edge[i] = {a, b, w};
	}
	
	bellman_ford();
	
	if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
	else cout << dist[n] << endl;
	
	return 0;
	
}
