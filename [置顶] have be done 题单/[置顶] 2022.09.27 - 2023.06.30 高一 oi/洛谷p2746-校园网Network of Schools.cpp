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

const int N = 110;
int n; 
int h[N << 1], idx;
struct node
{
	int nxt, val;
}edge[N * N];
// node
int timestamp, scc_cnt;
int dfn[N << 1], low[N << 1], id[N << 1];
bool st[N << 1];
int stk[N << 1], top;
int ind[N << 1], outd[N << 1];
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
	stk[++ top] = u, st[u] = true;
	
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
	
	if (dfn[u] == low[u])
	{
		int j;
		++ scc_cnt;
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
	input(n);
	for (int i = 1; i <= n; i ++)
	{
		int x; input(x);
		while (x)
		{
			add(i, x);
//			cout << i << " -> " << x << endl;	
			input(x);
		}
	}
	// input
	
	for (int i = 1; i <= n; i ++)
		if (!dfn[i]) tarjan(i);
	// tarjan
	
	for (int i = 1; i <= n; i ++)
		for (int j = h[i]; ~j; j = edge[j].nxt)
		{
			int k = edge[j].val;
//			cout << "judge" << i << " " << k << endl; 
			int a = id[i], b = id[k];
			if (a != b)
			{
				ind[b] ++, outd[a] ++;
//				cout << a << " -> " << b << endl;
			}
		}
//	for (int i = 1; i <= n; i ++)
//		cout <<  i << "--belongs to --" << id[i] << endl;
//	
//	for (int i = 1; i <= scc_cnt; i ++)
//		cout << i << " indegree " << ind[i] << " outdegree " << outd[i] << " " << endl;
//	cout << endl;
	
	if (scc_cnt == 1)
	{
		puts("1");
		puts("0");
		return 0;
	}
	
	int sub1 = 0, sub2 = 0;
	for (int i = 1; i <= scc_cnt; i ++)
	{
		if (!ind[i]) sub1 ++;
		if (!outd[i]) sub2 ++;
	}
	cout << sub1 << endl << max(sub1, sub2) << endl;
	return 0;
}
