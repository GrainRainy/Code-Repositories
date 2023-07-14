#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10, M = 1e4 + 10;

int n, m, k;
int fa[N];
int chosed[M];

struct node
{
	int a, b, w;
	
	bool operator < (const node &t) const
	{
		return w < t.w;
	}
}edge[M];

int find(int x)
{
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

int kruskal()
{
	sort(edge + 1, edge +  m + 1);
	
	int ans = 0, cnt = 0;
	for (int i = 1; i <= m; i ++)
	{
		int p = find(edge[i].a), q = find(edge[i].b);
		if (p != q)
		{
			fa[p] = q;
			cnt ++;
			ans += edge[i].w;
			chosed[cnt] = edge[i].w;
		}
	}
	
	int cnts = n - cnt;
	if (cnts > k) return -1;
	if (cnts == k) return ans;
	else
	{
		sort(chosed + 1, chosed + cnt + 1, greater<int>());
		int need = k - cnts;
		for (int i = 1; i <= need; i ++)
			ans -= chosed[i];
		return ans;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++)
		fa[i] = i;
	for (int i = 1; i <= m; i ++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edge[i] = {a, b, w};
	}
	if (k > n)
	{
		puts("No Answer");
		return 0;
	}
	
	int t = kruskal();
	if (t == -1) puts("No Answer");
	else cout << t << endl;
	
	return 0;
}
