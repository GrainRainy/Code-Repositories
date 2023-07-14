#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m, k;
int father[N];

int idx;
struct node
{
	int a, b, w;
	
	bool operator < (const node &t) const
	{
		return w < t.w;
	}
}edge[N * N];

int find(int x)
{
	if (father[x] != x) father[x] = find(father[x]);
	return father[x];
}

void kruskal()
{
	for (int i = 1; i <= n; i ++)
		father[i] = i;
	sort(edge + 1, edge + idx + 1);
	
	int ans = 0;
	for (int i = 1; i <= idx; i ++)
	{
		int p = find(edge[i].a), q = find(edge[i].b);
		if (p != q)
		{
			father[p] = q;
			ans += edge[i].w;
		}
	}
	cout << ans << endl;
	return;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
		{
			int tmp;
			cin >> tmp;
			if (j > i) edge[++ idx] = {i, j, tmp};
		}
	
	kruskal();
	
	return 0;
}
