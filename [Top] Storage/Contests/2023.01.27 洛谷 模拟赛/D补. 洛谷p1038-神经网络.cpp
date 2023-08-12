#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m;
int h[N], idx;
struct node
{
	int val, nxt, w;
}edge[N << 1];

bool od[N]; // outdegree

int c[N];
bool st[N];

queue<int> q;

void topsort()
{
	while (!q.empty())
	{
		int t = q.front(); q.pop();
		// st[t] = false;
		if (c[t] < 0) continue;
		for (int i = h[t]; i != -1; i = edge[i].nxt)
		{
			int j = edge[i].val;
			c[j] += edge[i].w * c[t];
			if (!st[j])
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
	int u;
	for (int i = 1; i <= n; i ++)
	{
		h[i] = -1;
		cin >> c[i] >> u;
		if (c[i]) q.push(i), st[i] = true;
		else c[i] -= u; // ? ? ? why need 'else'
	}
	
	for (int i = 1; i <= m; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		od[a] = true;
	}
	
	topsort();
	
	bool flag = 0;
	for (int i = 1; i <= n; i ++)
		if (!od[i] && c[i] > 0)
		{
			cout << i << " " << c[i] << endl;
			flag = true;
		}
	if (!flag) cout << "NULL" << endl;
	
	return 0;
	
}
