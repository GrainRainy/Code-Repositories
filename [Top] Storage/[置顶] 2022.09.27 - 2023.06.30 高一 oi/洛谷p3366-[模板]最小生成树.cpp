#include <bits/stdc++.h>

using namespace std;

const int N = 5010, M = 2e5 + 10;

int n, m;
int father[N];

int idx;
struct node
{
	int a, b, w;
	
	bool operator < (const node &t) const
	{
		return w < t.w;
	}
	
}edge[M];

void add(int a, int b, int c)
{
	edge[++ idx] = {a, b, c};
}

int find(int x)
{
	if (father[x] != x) father[x] = find(father[x]);
	return father[x]; 
}

void kruskal()
{
	for (int i = 1; i <= n; i ++)
		father[i] = i;
	stable_sort(edge + 1, edge + m + 1);
	
	int ans = 0, cnt = 0; 
	for (int i = 1; i <= m; i ++)
	{
		int p = find(edge[i].a), q = find(edge[i].b);
		if (p != q)
		{
			father[p] = q;
			cnt ++;
			ans += edge[i].w;
		}
	}
	if (cnt < n - 1) puts("orz");
	else cout << ans << endl;
	return;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	
	kruskal();
	
	return 0;
}
