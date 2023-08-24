#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 10010;

int dist[N], last[N];

struct node{
	int a, b, w;
}edge[M];
// ��ʾ�� a �� b ��һ����ȨΪ w �ı� 

int n, m, k;

void bellman_ford()
{
	
	
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	for (int i = 0; i < k; i ++)
	{
		memcpy(last, dist, sizeof dist);
		// ���� dist ���飬�洢��һ�ε������
		for (int j = 0; j < m; j ++)
		{
			int a = edge[j].a, b = edge[j].b, w = edge[j].w;
			dist[b] = min(dist[b], last[a] + w);
			// ʹ����һ�ε���������£���ֹǰ��Ľ��Ӱ����� 
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
