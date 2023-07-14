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

int cnt[N];
// 抽屉原理判负环 

priority_queue<PII, vector<PII>, greater<PII> > heap;
// 双关键字，节点大小以及节点编号 

void add(int a, int b, int c)
{
	edge[++ idx].to = b;
	edge[idx].w = c;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

bool spfa()
{
	queue<int> q;
	// 存储所有待更新的点 
	for (int i = 1; i <= n; i++)
	{
		st[i] = true;
		q.push(i);
	}
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
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n) return true;
				if (!st[j]) q.push(j), st[j] = true;
			}
		}
	}
	return false;
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
	if (spfa()) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
	
}
