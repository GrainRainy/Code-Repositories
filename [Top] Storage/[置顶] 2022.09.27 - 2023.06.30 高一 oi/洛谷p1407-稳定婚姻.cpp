#include <iostream>
#include <cstring>
#include <map>
using namespace std;

const int N = 4e3 + 10;
const int M = 20000 + 10;
int n, m;
map<string, int> couple;
// basic things
int h[N << 1], idx = 0;
struct node
{
	int val, nxt;
}edge[M + N];
// node
int timestamp, scc_cnt;
int stk[N << 1], top;
int dfn[N << 1], low[N << 1], id[N << 1];
bool in_s[N << 1];
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
		else if (in_s[j])
			low[u] = min(low[u], dfn[j]);
	}
	
	if (dfn[u] == low[u])
	{
		int j;
		++ scc_cnt;
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
	cin >> n;
	string boy, girl;
	for (int i = 1; i <= n; i ++)
	{
		cin >> girl >> boy;
		couple[girl] = i;
		couple[boy] = i + n;
		add(i, i + n);
	}
	cin >> m;
	for (int i = 1; i <= m; i ++)
	{
		cin >> girl >> boy;
		add(couple[boy], couple[girl]);
	}
	// input
	for (int i = 1; i <= (n << 1); i ++)
		if (!dfn[i]) tarjan(i);
	
	for (int i = 1; i <= n; i ++)
	{
		if (id[i] == id[i + n])
			puts("Unsafe");
		else puts("Safe");
	}
	return 0;		
}
