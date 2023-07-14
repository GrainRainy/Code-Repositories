#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 5000010;
const int M = 10000010;
int h[N], idx;
struct node{
	int to, nxt, w;
}edge[M << 1];
// dij
int n, m, t;
int dist[N];
bool st[N]; 

priority_queue<PII, vector<PII>, greater<PII> > heap;

void add(int a, int b, int c)
{
	edge[++ idx].to = b;
	edge[idx].w = c;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	heap.push({0, 1});
	while (heap.size())
	{
		PII tmp = heap.top();
		heap.pop();
		
		int distance = tmp.first;
		int ver = tmp.second;
		if (st[ver]) continue;
		st[ver] = true;
		for (int i = h[ver]; i != -1; i = edge[i].nxt)
		{
			int j = edge[i].to;
			if (dist[j] > distance + edge[i].w)
			{
				dist[j] = distance + edge[i].w;
				heap.push({dist[j], j});
			}
		 } 
	}
}

int main()
{
	freopen("short.in", "r", stdin);
	freopen("short.out", "w", stdout);
	cin >> n >> m >> t;
	memset(h, -1, sizeof h);
	while (m --)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	
	dijkstra();
		
	if (dist[t] == 0x3f3f3f3f) puts("-1");
	else cout << dist[t] << endl;
	
	return 0;
	
}
