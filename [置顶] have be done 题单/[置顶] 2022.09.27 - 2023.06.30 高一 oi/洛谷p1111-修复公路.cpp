#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10, M = 1e5 + 10;

int n, m;
int father[N];

int idx;
struct route
{
	int a, b, w;
	
	bool operator < (const route &t) const
	{
		return  w < t.w;
	}
	
}edge[M << 1];

void add(int a, int b, int w)
{
	edge[++ idx].a = a;
	edge[idx].b = b;
	edge[idx].w = w;
}

int find(int x)
{
	if (father[x] != x) father[x] = find(father[x]);
	return father[x];
}

int kruskal()
{
	sort(edge + 1, edge + m + m + 1);
	
	int maxn = -1, cnt = 0;
	for (int i = 1; i <= m << 1; i ++)
	{
		int p = find(edge[i].a), q = find(edge[i].b);
		if (p != q)
		{
			maxn = max(maxn, edge[i].w);
			father[p] = q;
			cnt ++;
		}
	}
	if (cnt < n - 1) return -1;
	return maxn;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		add(a, b, w), add(b, a, w);
	}
		
	// input;
	
	for (int i = 1; i <= n; i ++)
		father[i] = i;
	
	cout << kruskal() << endl;
	
	return 0;
}
