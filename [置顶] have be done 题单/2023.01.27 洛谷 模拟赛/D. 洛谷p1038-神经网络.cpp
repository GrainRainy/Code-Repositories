#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m;
int h[N], idx;
struct node
{
	int val, nxt, w;
}edge[N << 1];

int id[N], od[N]; // indegree and outdegree

int c[N], u[N];
bool st[N];

void topsort()
{
	queue<int> q;
	
	for (int i = 1; i <= n; i ++)
		if (c[i]) q.push(i);
	
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		
		for (int i = h[t]; i != -1; i = edge[i].nxt)
		{
			int j = edge[i].val;
			c[j] += edge[t].w * c[t];
			if (c[j] - u[j] > 0 && !st[j])
			{
				q.push(j);
				st[j] = true;
			}
		}
	}
}

void add(int a, int b, int w)
{
	edge[++ idx].val = b;
	edge[idx].nxt = h[a];
	edge[idx].w = w;
	h[a] = idx;
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	
	for (int i = 1; i <= n; i ++)
		cin >> c[i] >> u[i];
	
	for (int i = 1; i <= m; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		id[b] ++;
		od[a] ++;
	}
	
	topsort();
	
	bool flag = 0;
	for (int i = 1; i <= n; i ++)
		if (!od[i] && c[i] - u[i] > 0)
		{
			cout << i << " " << c[i] - u[i] << endl;
			flag = true;
		}
	if (!flag) cout << "NULL" << endl;
	
	return 0;
	
}
