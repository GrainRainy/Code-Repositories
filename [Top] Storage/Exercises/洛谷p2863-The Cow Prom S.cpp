#include <iostream>
#include <cstring>
#include <cctype>
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

const int N = 1e4 + 10;
const int M = 5e4 + 10;
int n, m;
// basic things
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
int siz[N];
// tarjan

void add(int a, int b)
{
	edge[++ idx].val = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++ timestamp;
	stk[++ top] = u; st[u] = true;
	
	for (int i = h[u]; ~i; i = edge[i].nxt)
	{
		int j = edge[i].val;
		
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if (st[j]) low[u] = min(low[u], dfn[j]);
	}
	
	if (low[u] == dfn[u])
	{
		int j;
		scc_cnt ++;
		do
		{
			j = stk[top --];
			id[j] = scc_cnt;
			st[j] = false;
			siz[scc_cnt] ++;
		} while (j != u);
	}
}

signed main()
{
	memset(h, -1, sizeof h);
	input(n), input(m);
	while (m --)
	{
		int a, b;
		input(a), input(b);
		add(a, b);
	}
	// input
	for (int i = 1; i <= n; i ++)
		if (!dfn[i]) tarjan(i);
	// tarjan
	
	int ans = 0;
	for (int i = 1; i <= scc_cnt; i ++)
		if (siz[i] > 1) ans ++;
	cout << ans << endl;
	return 0;
}
