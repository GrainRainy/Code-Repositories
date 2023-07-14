#include <bits/stdc++.h>
using namespace std;

const int N = 4e4 + 10;

int n, m;
int depth[N], fa[N][16];
// 2^15 contains 1 ~ 32768, suitable for the task
queue<int> q;
// bfs ���� 

int h[N], idx;
struct node
{
	int val, nxt;
}edge[N << 1];

void add(int a, int b)
{
	edge[++ idx].val = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

void bfs(int root)
{
	memset(depth, 0x3f, sizeof depth);
	
	depth[0] = 0, depth[root] = 1;
	// �����ڱ�����ֹ������ 
	q.push(root);
	while (q.size())
	{
		int t = q.front(); q.pop();
		for (int i = h[t]; i != -1; i = edge[i].nxt)
		{
			int j = edge[i].val;
			if (depth[j] > depth[t] + 1)
			// j δ��������
			{
				depth[j] = depth[t] + 1;
				q.push(j);
				fa[j][0] = t;
				for (int k = 1; k <= 15; k ++)
					fa[j][k] = fa[fa[j][k - 1]][k - 1];
			}
		}
	}
}

int lca(int a, int b)
// �� a, b �������������ѯ�� 
{
	if (depth[a] < depth[b]) swap(a, b);
	for (int k = 15; k >= 0; k --)
		if (depth[fa[a][k]] >= depth[b]) a = fa[a][k];
		// ���������ڵ㣬depth[fa[a][k]] == 0, ���޷����� 
	if (a == b) return b;
	for (int k = 15; k >= 0; k --)
		if (fa[a][k] ^ fa[b][k]) // equals to fa[a][k] != fa[b][k]
			a = fa[a][k], b = fa[b][k];
	return fa[a][0];
	// �� fa[b][0]
}

int main()
{
	cin >> n;
	memset(h, -1 ,sizeof h);
	
	int root = 0;
	for (int i = 1; i <= n; i ++)
	{
		int a, b;
		cin >> a >> b;
		if (b == -1) root = a;
		else add(a, b), add(b, a);
	}
	
	bfs(root);
	// Ԥ���� depth ��Ⱥ� fa��������
	
	cin >> m;
	while (m --)
	{
		int a, b;
		cin >> a >> b;
		int p = lca(a, b);
		if (p == a) cout << "1" << endl;
		else if (p == b) cout << 2 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
