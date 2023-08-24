#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int MOD = 80112002;

int n, m;
int h[N], e[N], ne[N], idx; // 邻接表 
int q[N]; // 队列 
int in[N], out[N]; // 出度入度 
int f[N]; // 路径数量 
int ans; // 答案 

bool topsort()
{
	int hh = 0, tt = -1;
	
	for (int i = 1; i <= n; i ++)
		if (in[i] == 0)
		{
			q[++ tt] = i;
			f[i] ++;
		}
		
	while (hh <= tt)
	{
		int t = q[hh ++];
		
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			f[j] = (f[j] + f[t]) % MOD;
			in[j] --;
			if (in[j] == 0) q[++ tt] = j;
		}
	}
}

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

int main()
{
	cin >> n >> m;
	
	memset(h, -1, sizeof h);
	
	for(int i = 1; i <= m; i ++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		in[b] ++;
		out[a] ++;
	}
	
	topsort();
	
	for (int i = 1; i <= n; i++)
	{
		if (out[i] == 0)
			ans = (ans + f[i]) % MOD;
	}

	cout << ans << endl;
	
	return 0;
	
}
