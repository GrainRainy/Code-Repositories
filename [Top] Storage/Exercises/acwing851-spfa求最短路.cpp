#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 1001000;

int h[N], idx;
struct node
{
	int to, nxt, w;
}edge[N];

int n, m;
int dist[N];
bool st[N]; 

priority_queue<PII, vector<PII>, greater<PII> > heap;
// 双关键字，节点大小以及节点编号 

void add(int a, int b, int c)
{
	edge[++ idx].to = b;
	edge[idx].w = c;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

void spfa()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	queue<int> q;
	// 存储所有待更新的点 
	q.push(1);
	st[1] = true;
	//  存储当前点是否在队列中
	while (q.size())
	{
		int t = q.front();
		q.pop();
		
		st[t] = false;
		for (int i = h[t]; i != -1; i = edge[i].nxt)
		{
			int j = edge[i].to;
			if (dist[j] > dist[t] + edge[i].w)
			{
				dist[j] = dist[t] + edge[i].w;
				if (!st[j]) q.push(j), st[j] = true;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m --)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	spfa();
	
		
	if (dist[n] == 0x3f3f3f3f) puts("-1");
	else cout << dist[n] << endl;
	
	return 0;
	
}
