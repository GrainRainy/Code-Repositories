#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = N << 1;
// ���ڴ洢����ߣ���Ҫ�������ռ�洢 

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
// ���شӵ�ǰ��������������󳤶�  
// fahter ��ֹ dfs ��������
{
	int dist = 0;
	int d1 = 0, d2 = 0;
	// ��ʾ�Ե�ǰ�ڵ�Ϊ��ʼλ�ã������������������γ����� 
	
	for (int i = h[u]; i != -1; i = edge[i].nxt)
	{
		int j = edge[i].to;
		if (j == father) continue;
		int d = dfs(j, u) + edge[i].w;
		dist = max(dist, d);
		
		if (d >= d1) d2 = d1, d1 = d;
		else if (d > d2) d2 = d;
		// �����ֵ�ʹδ�ֵ����ά�� 
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
