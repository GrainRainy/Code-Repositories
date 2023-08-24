#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath> 
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

const int N = 1e5 + 10;
const int M = 3e5 + 10;
int n, m;
int h[N], idx;
struct node
{
	int nxt, val;
}edge[M];
// node
int timestamp, scc_cnt;
int dfn[N], low[N], id[N];
int stk[N], top;
bool st[N];
// tarjan

int ind[N];

void add(int a, int b)
{
	edge[++ idx].val = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++ timestamp;
	stk[++ top] = u, st[u] = true;
	
	for (int i = h[u]; ~i; i = edge[i].nxt)
	{
		int k = edge[i].val;
		
		if (!dfn[k])
		{
			tarjan(k);
			low[u] = min(low[u], low[k]);
		}
		else if (st[k]) low[u] = min(low[u], dfn[k]);
	}
	
	if (dfn[u] == low[u])
	{
		int j;
		scc_cnt ++;
		
		do
		{
			j = stk[top --];
			id[j] = scc_cnt;
			st[j] = false;
		} while (j != u);
	}
}

int main()
{
	memset(h, -1, sizeof h);
	input(n), input(m);
	while (m --)
	{
		int a, b;
		input(a), input(b);
		add(a, b);
	}
	
	for (int i = 1; i <= n; i ++)
		if (!dfn[i]) tarjan(i);
	
	for (int i = 1; i <= n; i ++)
		for (int j = h[i]; ~j; j = edge[j].nxt)
		{
			int k = edge[j].val;
			if (id[i] != id[k]) ind[id[k]] ++;
		}
	
	int maxn = 0;
	for (int i = 1; i <= scc_cnt; i ++)
		if (!ind[i]) maxn ++;
	
	for (int i = n - scc_cnt; i <= n - maxn; i ++)
		cout << i << endl;
}

