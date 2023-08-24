#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;

const int N = 2e3 + 10;
const int M = 3e3 + 10;

int h[N], idx;
struct node
{
	int to, nxt, w;
}edge[M << 1];

void add(int a, int b, int c)
{
	edge[++ idx].to = b;
	edge[idx].w = c;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

int dist[N], cnt[N];
bool st[N];

int n, m;

bool spfa()
{
	queue<int> q;
	q.push(1), st[1] = 1;
	
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
				if (cnt[j] >= n) return 1;
				if (!st[j]) q.push(j), st[j] = 1;
			}
		}
	}
	return false;
}

void solve()
{
	memset(h, -1, sizeof h);
	memset(cnt, 0, sizeof cnt);
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	idx = 0;
	dist[1] = 0;
	
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c >= 0) add(a, b, c), add(b, a, c);
		else add(a, b, c);
	}
	
//	for (int i = h[3]; i != -1; i = edge[i].nxt)
//	{
//		cerr << edge[i].to << " " << edge[i].w << "  ";
//	}
//	cerr << endl;
	
	if (spfa()) cout << "YES" << endl;
	else cout << "NO" << endl;
	return;
}

int main()
{
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
