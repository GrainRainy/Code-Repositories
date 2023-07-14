#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e5 + 10;

int n;
int head[N], idx;
struct node{
	int nxt, to;
}edge[N << 1];
// graph
int timestamp, scc_cnt;
int stk[N], top;
bool st[N];
int dfn[N], low[N], id[N]; 
// tarjan
int indg[N], outdg[N];
// topsort

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

inline void tarjan(int u){
	dfn[u] = low[u] = ++ timestamp;
	stk[++ top] = u, st[u] = true;
	
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int j = edge[i].to;
		if (!dfn[j]){
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if (st[j]) low[u] = min(low[u], dfn[j]);
	}
	
	if (dfn[u] == low[u]){
		int tmp;
		scc_cnt ++;
		do{
			tmp = stk[top --];
			st[tmp] = false;
			id[tmp] = scc_cnt;
		} while (tmp != u);
	}
}

signed main(){
	memset(head, -1, sizeof head);
	
	input(n);
	for (int i = 1; i <= n; i ++){
		int tmp;
		while (input(tmp), tmp) add(i, tmp);
	}
	
	for (int i = 1; i <= n; i ++)
		if (!dfn[i]) tarjan(i);
	
	if (scc_cnt == 1) return cout << 1 << endl << 0 << endl, 0;
	// special judge
	
	for (int i = 1; i <= n; i ++)
		for (int j = head[i]; ~j; j = edge[j].nxt){
			int t = edge[j].to;
			if (id[i] != id[t]){
				indg[id[t]] ++, outdg[id[i]] ++;
			}
		}
	// init
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= scc_cnt; i ++){
		if (!indg[i]) ans1 ++;
		if (!outdg[i]) ans2 ++;
	}
	
	cout << ans1 << endl << max(ans1, ans2) << endl;
	return 0;
}
