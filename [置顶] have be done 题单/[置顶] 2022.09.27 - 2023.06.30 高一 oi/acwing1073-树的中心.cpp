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
// d1 ��ʾ�Ӹõ������н��������
// d2 ��ʾ�Ӹõ������н��Ĵγ����� 
int up[N];
// up ��ʾ�ӵ�ǰ�������н�������� 
int p1[N], p2[N];
// ���ڴ洢��ߺʹγ���������ת�ƶ��� 

void add(int a, int b, int c)
{
	edge[++ idx].to = b;
	edge[idx].w = c;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

int dfs_d(int u, int father)
// ��� u �������ߵ��·�� 
{
	
	d1[u] = d2[u] = -INF;
	// Ϊ��ʵ����Ȩ���д�����ʼֵ��Ϊ������
	for (int i = h[u]; i != -1; i = edge[i].nxt)
	{
		int j = edge[i].to;
		if (j == father) continue;
		// ����õ������������ģ���ôֱ������
		int d = dfs_d(j, u) + edge[i].w;
		// ȡ�����µ������ 
		if (d >= d1[u])
		{
			d2[u] = d1[u], d1[u] = d;
			p2[u] = p1[u], p1[u] = j;
		}
		else if (d > d2[u]) d2[u] = d, p2[u] = j;
	}
	
	if (d1[u] == -INF) d1[u] = d2[u] = 0;
	// ����Ҷ�ڵ�����⴦�� 
	
	return d1[u];
}

void dfs_u(int u, int father)
{
	for (int i = h[u]; i != -1; i = edge[i].nxt)
	{
		int j = edge[i].to;
		if (j == father) continue;
		
		if (p1[u] == j) up[j] = max(up[u], d2[u]) + edge[i].w;
		//  �·���ɸýڵ���������ת�ƶ�������ʹ�ôδ�ֵ 
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
	
	dfs_d(1, -1); // �������� 
	dfs_u(1, -1);
	
	int res = INF;
	for (int i = 1; i <= n; i ++)
		res = min(res, max(d1[i], up[i]));
	cout << res << endl;
	
	return 0;
}
