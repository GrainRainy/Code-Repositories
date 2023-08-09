#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1010, M = 100010;
const int INF = 1e8;

int h[N], idx;
struct node
{
	int from;
	int nxt, to, w;
	
	bool operator < (const node &t) const
	{
		return w < t.w;
	}
	
}edge[M];

int n, m;
int dist[N], father[N];

void add(int x, int y, int z)
{
	edge[++ idx].from = x;
	edge[idx].to = y;
	edge[idx].nxt = h[x];
	edge[idx].w = z;
	h[x] = idx;
}

int find(int u)
{
	if (father[u] == u) return u;
	else find(father[u]);
}

LL kruskal()
{
	LL maxn = -INF;
	sort(edge + 1, edge + (m << 1) + 1);
	
	for (int i = 1; i <= (m << 1); i += 2)
	{
		
		LL p = find(edge[i].from);
		LL q = find(edge[i].to);
		
		// cerr << i << " " << edge[i].from << " " << edge[i].to << endl;
		
		// cerr << endl << edge[i].from << " " << edge[i].to << endl;
		
		// cerr << p << " " << q << endl;
		
		if (p == q) continue;
		else
		{
			father[p] = q;
			maxn = (edge[i].w > maxn) ? edge[i].w : maxn;
		}
	}
	
	return maxn;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z), add(y, x, z);
	}
	
	for (int i = 1; i <= n; i ++)
		father[i] = i;
	
	LL ans = kruskal();
		
	int cnt;
	for (int i = 1; i <= n; i ++)
		if (father[i] == i) cnt ++;
	if (cnt > 1)
	{
		cout << "-1" << endl;
		return 0;
	}
	else cout << ans << endl;
	return 0;
}
