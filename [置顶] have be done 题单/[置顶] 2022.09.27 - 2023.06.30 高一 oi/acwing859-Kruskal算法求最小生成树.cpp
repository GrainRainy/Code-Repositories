#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

struct node
{
	int a, b, w;
	
	bool operator < (const node &t) const
	{
		return w < t.w;
	}
}edge[N];

int n, m;
int p[N]; // 并查集数组

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void kruskal()
{
	sort(edge, edge + m);
	for (int i = 1; i <= n; i ++) p[i] = i;
	// 初始化并查集 
	
	int res = 0, cnt = 0;
	// res 存储最小生成树中边权之和
	// cnt 存储最小生成树中边数 
	for (int i = 0; i < m; i ++)
	{
		int a = edge[i].a, b = edge[i].b, w = edge[i].w;
		
		a = find(a), b = find(b);
		
		if (a != b)
		{
			p[a] = b; 
			res += w;
			cnt ++;
		}
	}
	
	if (cnt < n - 1) puts("impossible");
	else cout << res << endl;
	
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m ;i ++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edge[i] = {a, b, w};
	}
	
	kruskal();
	
		cerr << endl;
	for (int i = 1; i <= n ; i++)
		cerr << p[i] << " ";
	cerr << endl;
	
	return 0;
}
