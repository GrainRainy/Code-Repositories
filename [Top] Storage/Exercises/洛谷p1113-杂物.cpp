#include <bits/stdc++.h>


const int N = 1e5 + 10;
const int M = 1e7 + 10;

using namespace std;

int indg[N];
int t[N], maxt[N];

int h[N], idx;
struct node
{
	int nxt, to;
}edge[N];

void add(int a, int b)
{
	edge[++ idx].to = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

int n, ans;

void topsort()
{
	queue<int> q;
	
	for (int i = 1; i <= n; i ++)
		if (!indg[i])
		{
			q.push(i);
			maxt[i] = t[i];
		}
	
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for (int k = h[u]; k != -1; k = edge[k].nxt)
		{
			int v = edge[k].to;
			indg[v] --;
			maxt[v] = max(maxt[u] + t[v], maxt[v]);
			ans = max(ans, maxt[v]);
			
			if (!indg[v]) q.push(v);
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	int x, y;
	for (int i = 1; i <= n; i ++)
	{
		cin >> x >> y;
		t[x] = y;
		cin >> y;
		while (y)
		{
			add(y, x);
			indg[x] ++;
			cin >> y;
		}
	}
	
	topsort();
	
	cout << ans << endl;
	
	return 0;
}
