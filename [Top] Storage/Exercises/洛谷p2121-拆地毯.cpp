#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

int n, m, k;
int sum = 0;

int father[N];
int find(int x)
{
	if (father[x] != x) father[x] = find(father[x]);
	return father[x];
}

int idx;
struct node
{
	int a, b, w;
	
	bool operator < (const node &t) const
	{
		return w > t.w;
	}
}edge[N];
void add(int a, int b, int c)
{
	edge[++ idx] = {a, b, c};
}

void kruskal()
{
	sort(edge + 1, edge + m + 1);
	
	int cnt = 0;
	for (int i = 1; i <= m; i ++)
	{
		int p = find(edge[i].a), q = find(edge[i].b);
		if (p != q)
		{
			father[p] = q;
			sum += edge[i].w;
			cnt ++;
		}
		if (cnt == k) return;
	}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
	{
		int u, v, g;
		cin >> u >> v >> g;
		add(u, v, g);
	}
	for (int i = 1; i <= n; i++)
		father[i] = i;
	
	kruskal();
	
	cout << sum << endl;
	
	return 0;
}
