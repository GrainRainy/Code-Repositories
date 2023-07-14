#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <unordered_set>
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

typedef long long LL;

const int N = 1e5 + 10;
const int M = 1e6 + 10;
int n, m, MOD;
// basic things
int h[N], nh[N], idx;
struct node
{
	int val, nxt;
}edge[M << 1];
// node
int timestamp, scc_cnt;
int stk[N], top;
int dfn[N], low[N], id[N], siz[N];
bool in_s[N];
// tarjan
int f[N], g[N];
// topsort

void add(int h[], int a, int b)
{
	edge[++ idx].val = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++ timestamp;
	stk[++ top] = u, in_s[u] = true;
	
	for (int i = h[u]; ~i; i = edge[i].nxt)
	{
		int j = edge[i].val;
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if (in_s[j])
			low[u] = min(low[u], dfn[j]);
	}
	
	if (dfn[u] == low[u])
	{
		int j;
		scc_cnt ++;
		do
		{
			j = stk[top --];
			in_s[j] = false;
			id[j] = scc_cnt;
			siz[scc_cnt] ++;
		} while (j != u);
	}
}

int main()
{
	memset(h, -1, sizeof h);
	memset(nh, -1, sizeof nh);
	
	input(n), input(m), input(MOD);
	while (m --)
	{
		int a, b;
		input(a), input(b);
		add(h, a, b);
	}
	// input
	for (int i = 1; i <= n; i ++)
		if (!dfn[i]) tarjan(i);
	// tarjan
	
	unordered_set<LL> hash;
	for (int i = 1; i <= n; i ++)
		for (int j = h[i]; ~j; j  = edge[j].nxt)
		{
			int k = edge[j].val;
			int tmpa = id[i], tmpb = id[k];
			LL tmphash = tmpa * 100000ll + tmpb;
			if (tmpa != tmpb and !hash.count(tmphash))
			{
				add(nh, tmpa, tmpb);
				hash.insert(tmphash);
			}
		}
	
	for (int i = scc_cnt; i > 0; i --)
	{
		if (!f[i])
		{
			f[i] = siz[i];
			g[i] = 1;
		}
		for (int j = nh[i]; ~j; j = edge[j].nxt)
		{
			int k = edge[j].val;
			if (f[k] < f[i] + siz[k])
			{
				f[k] = f[i] + siz[k];
				g[k] = g[i];
			}
			else if (f[k] == f[i] + siz[k])
				g[k] = (g[k] + g[i]) % MOD;
		}
	}
	
	int subt1 = 0, subt2 = 0;
	for (int i = 1; i <= scc_cnt; i ++)
	{
		if (f[i] > subt1)
		{
			subt1 = f[i];
			subt2 = g[i];
		}
		else if (f[i] == subt1)
			subt2 = (subt2 + g[i]) % MOD;
	}
	
	cout << subt1 << endl << subt2 << endl;
	return 0;
}
