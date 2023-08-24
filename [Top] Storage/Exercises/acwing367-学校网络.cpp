#include <iostream>
#include <algorithm>
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

const int N = 110;
const int M = N * N;
int n;
int h[N], idx;
struct node
{
	int nxt, val;
}edge[M];
// node
int stk[N], top;
int timestamp;
int dfn[N], low[N], id[N];
bool in_s[N]; 
int scc_cnt, ind[N], outd[N];
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
	stk[++ top] = u; in_s[u] = true;
	
	for (int i = h[u]; ~i; i = edge[i].nxt)
	{
		int j = edge[i].val;
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if (in_s[j]) low[u] = min(low[u], dfn[j]);
	}

	if (dfn[u] == low[u])
	{
		scc_cnt ++;
		int j;
		do
		{
			j = stk[top --];
			in_s[j] = false;
			id[j] = scc_cnt;
		} while (j != u);
	}
}

int main()
{
	memset(h, -1, sizeof h);
	input(n);
	for (int i = 1; i <= n; i ++)
	{
		int a;
		while (input(a), a) add(i, a);
	}
		
	for (int i = 1; i <= n; i ++)
		if (!dfn[i]) tarjan(i);
	
	for (int i = 1; i <= n; i ++)
		for (int j = h[i]; ~j; j = edge[j].nxt)
			if (id[i] != id[edge[j].val])
				++ ind[id[edge[j].val]], ++ outd[id[i]];
	
	if (scc_cnt == 1)
	{
		cout << "1" << endl << "0" << endl;
		return 0;
	}
	int subt1 = 0, subt2 = 0;
	for (int i = 1; i <= scc_cnt; i ++)
	{
		if (!ind[i]) subt1 ++;
		if (!outd[i]) subt2 ++;
	}
		
	
	cout << subt1 << endl << max(subt1, subt2) << endl;
	return 0;
}
