#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template <typename T>
void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
void output(T x, char ed = '\n') // '\n' or ' ', remember to check
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++ tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp --] | '0');
	putchar(ed);
}

const int N = 2e5 + 10;
const int K = 19;
int n, t;
// basic things
int h[N], idx;
struct node
{
	int nxt, val;
}edge[N << 2];

void add(int a, int b)
{
	edge[++ idx].val = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}
// graphs
int dist[N], father[N][K];
void dfs(int u)
{
	memset(dist, 0x3f, sizeof dist);
	dist[0] = 0, dist[u] = 1;
	queue<int> q; q.push(u);
	// init
	while (q.size())
	{
		int t = q.front(); q.pop();
		for (int i = h[t]; ~i; i = edge[i].nxt)
		{
			int j = edge[i].val;
			if (dist[j] > dist[t] + 1)
			{
				dist[j] = dist[t] + 1;
				q.push(j);
				father[j][0] = t;
				for (int k = 1; k <= K; k ++)
					father[j][k] = father[father[j][k - 1]][k - 1];
			}
		}
	}
}

int lca(int a, int b)
{
	if (dist[a] < dist[b]) swap(a, b);
	for (int k = K; k >= 0; k --)
		if (dist[father[a][k]] >= dist[b]) a = father[a][k];
	if (a == b) return b;
	for (int k = K; k >= 0; k --)
		if (father[a][k] ^ father[b][k])
			a = father[a][k], b = father[b][k];
	return father[a][0];
}
// LCA

int get_dist(int a, int b)
{
	int tmp = lca(a, b);
	return abs(dist[a] - dist[tmp]) + abs(dist[b] - dist[tmp]);
}

bool judge()
{
	int x, y, a, b;
	input(x), input(y), input(a), input(b);
	int lcax = lca(x, y);
	int lcaa = lca(a, b);
	if (get_dist(a, b) == get_dist(a, lcax) + get_dist(lcax, b)) return true;
	if (get_dist(x, y) == get_dist(x, lcaa) + get_dist(lcaa, y)) return true;
	return false;
}

int main()
{
//	freopen("assassin.in","r",stdin);
//	freopen("assassin.out","w",stdout);
	memset(h, -1, sizeof h);
	input(n), input(t);
	for (int i = 1; i < n; i ++)
	{
		int a, b;
		input(a), input(b);
		add(a, b), add(b, a);
	}
	// input
	dfs(1);
	// init
	while (t --)
	{
		if (judge()) puts("YES");
		else puts("NO");
	}
	return 0;
}

