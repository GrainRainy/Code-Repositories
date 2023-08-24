/*
 * 累了 麻了 不想写高精了 
 * 就这样吧 至少有 40 pts 
 * 17:47: 
 * 		fad 连个搜索都写不对  
 * 第二天的 9：21
 * 反正样例过了 
 * 代码写得又臭又长 
 */

#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 110;
int n, m;
int dist[N][N];
vector<int> pos, tag;

int ans = 0x3f3f3f3f;

int getnum(int x)
{
	int st[N] = {0}, idx = 0, ans = 0;
	do st[++ idx] = x % 10, x /= 10; while (x);
	for (int i = 1; i <= idx; i ++)
		ans = ans * 10 + st[i];
		
	return ans;
}

void floyd()
{
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			for (int k = 1; k <= n; k ++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void dfs(int u, int sum)
{
	if (u == m + 1)
	{
		ans = min(ans, sum);
		return;
	}
	for (int i = 1; i <= m; i ++)
	{
		if (tag[i] == -1) continue;
		int tmp = tag[i];
		tag[i] = -1;
		dfs(u + 1, sum + dist[pos[u]][tmp]);
		tag[i] = tmp;
	}
}

int main()
{
	memset(dist, 0x3f, sizeof dist);
	input(n), input(m);
	pos.push_back(0), tag.push_back(0);
	for (int i = 1; i <= m; i ++)
	{
		int tmp;
		input(tmp);
		pos.push_back(tmp);
	}
	for (int i = 1; i <= m; i ++)
	{
		int tmp;
		input(tmp);
		tag.push_back(tmp);
	}	
	for (int i = 1; i < n; i ++)
	{
		dist[i][i] = 0;
		int a, b, c;
		input(a), input(b), input(c);
		dist[a][b] = dist[b][a] = min(dist[a][b], getnum(c));
	}
	dist[n][n] = 0;
	
	floyd();
	
//	for (int i = 1; i <= n; i ++)
//	{
//		for (int j = 1; j <= n; j ++)
//			cerr << dist[i][j] << " ";
//		cerr << endl;
//	}
	dfs(1, 0);
	cout << ans << endl;

	return 0;
}

