#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
template <typename T>
inline void input(T &x)
{
	x = 0; char c =getchar();
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
	int val, nxt;
}edge[M];
// node
int stk[N], top;
int timestamp, scc_cnt, dfn[N], low[N], id[N], siz[N];
bool in_s[N];
// tarjan
int ind[N], outd[N];
// topsort

void add(int a, int b)
{
	edge[++ idx].val = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++ timestamp;
	stk[++ top] = u; in_s[u] = true;
	
	for (int i = h[u]; ~i; i = edge[i].nxt)
	{
		int val = edge[i].val;
		if (!dfn[val])
		{
			tarjan(val);
			low[u] = min(low[u], low[val]);
		}
		else if (in_s[val])
			low[u] = min(low[u], dfn[val]);
	}
	
	if (dfn[u] == low[u])
	{
		scc_cnt ++;
		int y;
		do
		{
			y = stk[top --];
			in_s[y] = false;
			id[y] = scc_cnt;
			siz[scc_cnt] ++;
		} while (y != u);
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
			if (id[i] != id[edge[j].val])
				outd[id[i]] ++;
	
	int scc = 0, cnt = 0;
	for (int i = 1; i <= scc_cnt; i ++)
		if (!outd[i])
		{
			scc ++;
			cnt += siz[i];
			if (scc > 1)
			{
				cnt = 0;
				break;
			}
		}
	cout << cnt << endl;
	return 0;
}
