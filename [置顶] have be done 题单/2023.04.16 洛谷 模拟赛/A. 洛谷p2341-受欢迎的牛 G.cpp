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

const int N = 1e4 + 10;
const int M = 5e4 + 100;

int n, m;
int tmpa, tmpb;

int head[N], headb[N], idx;
struct Node{
	int nxt, to;
}edge[M << 2];
// graph
int timestamp, scc_cnt, top;
int id[N], dfn[N], low[N], cnt[N];
int stk[N];
bool st[N];
// tarjan
int outdg[N];
int dgcnt, dgans;
// topsort 

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

void tarjan(int u){
	dfn[u] = low[u] = ++ timestamp;
	stk[++ top ] = u, st[u] = true;
	
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int j = edge[i].to;
		if (!dfn[j]){
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if (st[j]){
			low[u] = min(low[u], dfn[j]);
		}
	}
	
	if (dfn[u] == low[u]){
		scc_cnt ++;
		int tmp;
		
		do{
			tmp = stk[top --];
			id[tmp] = scc_cnt;
			st[tmp] = false;
			cnt[scc_cnt] ++;
		} while (tmp != u);
	}
}

int main(){
	memset(headb, -1, sizeof headb);
	memset(head, -1, sizeof head);
	// init 
	input(n), input(m);
	for (int i = 1; i <= m; i ++){
		input(tmpa), input(tmpb);
		add(tmpa, tmpb);
	}
	// input
	for (int i = 1; i <= n; i ++){
		if (!dfn[i]) tarjan(i);
	}
	
	for (int i = 1; i <= n; i ++){
		for (int j = head[i]; ~j; j = edge[j].nxt){
			int u = edge[j].to;
			if (id[i] != id[u]){
				outdg[id[i]] ++;
			}
		}
	}
	
	for (int i = 1; i <= scc_cnt; i ++){
		if (!outdg[i]){ 
			dgcnt ++, dgans += cnt[i];
		}
	}
	
	if (dgcnt == 1) cout << dgans << endl;
	else cout << 0 << endl;
	return 0;
}
