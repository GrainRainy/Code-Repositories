#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 10;

int n;
int son[N][2], tnt;
int nums_xor[N];

int h[N], idx;
struct node
{
	int val, nxt, w;
}edge[N];

void add(int a, int b, int w)
{
	edge[++ idx].val = b;
	edge[idx].nxt = h[a];
	edge[idx].w = w;
	h[a] = idx;
}

void dfs(int u, int father)
{
	for (int i = h[u]; i != -1; i = edge[i].nxt)
	{
		if (edge[i].val != father)
		{
			nums_xor[edge[i].val] = nums_xor[u] ^ edge[i].w;
			dfs(edge[i].val, u);
		}
	}
}
// Î¬»¤µãµÄ xor 

void insert(int u)
{
	int p = 0;
	for (int i = 31; i >= 0; i --)
	{
		int c = (u >> i) & 1;
		if (!son[p][c]) son[p][c] = ++ tnt;
		p = son[p][c];
	}
}

int query(int u)
{
	int ans = 0;
	int p = 0;
	for (int i = 31; i >= 0; i --)
	{
		int c = (u >> i) & 1;
		if (son[p][!c])
		{
			ans += (1 << i);
			p = son[p][!c];
		}
		else p = son[p][c];
	}
	return ans;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i < n; i ++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		add(a, b, w), add(b, a, w);
	}
	
	dfs(1, -1);
	
	for (int i = 1; i <= n; i ++)
		insert(nums_xor[i]);
	int ans = -1;
	for (int i = 1; i <= n; i ++)
		ans = max(ans, query(nums_xor[i]));
		
	cout << ans << endl;
	return 0;
}
