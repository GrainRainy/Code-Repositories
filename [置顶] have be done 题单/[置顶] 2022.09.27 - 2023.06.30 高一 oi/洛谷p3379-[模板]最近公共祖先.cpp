#include <bits/stdc++.h>
using namespace std;
template <typename T>
void input(T &x)
{
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
void output(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++ tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp --] | '0');
	putchar(ed);
}
/*
 *  or ' ', remember to check
 */

const int N = 5e5 + 10;
const int K = 20;

int n, m, root;
int depth[N], fa[N][K + 10];

int h[N], idx;
struct node
{
	int val, nxt;
}edge[N << 1];

void add(int a, int b)
{
	edge[++ idx].val = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

void bfs(int root)
{
	memset(depth, 0x3f, sizeof depth);
	
	depth[0] = 0, depth[root] = 1;
	queue<int> q; q.push(root);
	
	while (q.size())
	{
		int t = q.front(); q.pop();
		for (int i = h[t]; ~i; i = edge[i].nxt)
		{
			int j = edge[i].val;
			if (depth[j] > depth[t] + 1)
			{
				depth[j] = depth[t] + 1;
				q.push(j);
				fa[j][0] = t;
				for (int k = 1; k <= K; k ++)
					fa[j][k] = fa[fa[j][k - 1]][k - 1];
			}
		}
	}
}

int lca(int a, int b)
{
	if (depth[a] < depth[b]) swap(a, b);
	for (int k = K; k >= 0; k --)
		if (depth[fa[a][k]] >= depth[b]) a = fa[a][k];
	if (a == b) return b;
	for (int k = K; k >= 0; k --)
		if (fa[a][k] != fa[b][k])
			a = fa[a][k], b = fa[b][k];
	return fa[a][0];
}

int main()
{
	memset(h, -1, sizeof h);
	input(n), input(m), input(root);
	int a, b;
	for (int i = 1; i < n; i ++)
	{
		input(a), input(b);
		add(a, b), add(b, a);
	}
	
	bfs(root);
	
	while (m --)
	{
		input(a), input(b);
		output(lca(a, b));
	}
	return 0;
}
