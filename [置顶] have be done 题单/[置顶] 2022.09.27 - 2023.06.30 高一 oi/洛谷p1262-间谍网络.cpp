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

const int N = 3000 + 10;
const int M = 8000 + 10;

int n, p, r;
int cost[N];
// basis
int head[N], idx;
struct node{
	int nxt, to;
}edge[M << 1];
int timestamp, scc_cnt;
int dfn[N], low[N], id[N];
int stk[N], top;
bool st[N];
int min_cost[N]; 
int indg[N], cant[N];
// tarjan

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
		++ scc_cnt;
		int tmp;
		do {
			tmp = stk[top --];
			st[tmp] = false;
			id[tmp] = scc_cnt;
			if (cost[tmp])
				min_cost[scc_cnt] = min(min_cost[scc_cnt], cost[tmp]);
		} while (tmp != u);
	}
	return;
}

int main(){
	memset(head, -1, sizeof head);
	memset(min_cost, 0x3f, sizeof min_cost);
	// init 
	
	input(n), input(p);
	for (int i = 1; i <= p; i ++){
		int tmpa, tmpb; input(tmpa), input(tmpb);
		cost[tmpa] = tmpb;
	}
	input(r);
	for (int i = 1; i <= r; i ++){
		int tmpa, tmpb; input(tmpa), input(tmpb);
		add(tmpa, tmpb);
	}
	// input
	for (int i = 1; i <= n; i ++)
		if (!dfn[i]) tarjan(i);
	// tarjan
	for (int i = 1; i <= n; i ++)
		for (int j = head[i]; ~j; j = edge[j].nxt){
			int k = edge[j].to;
			if (id[i] != id[k]) indg[id[k]] ++;
		}
	// new graph
	int ans = 0;
	bool fail = false;
	for (int i = 1; i <= scc_cnt; i ++){
		if (!indg[i]){
			if (min_cost[i] < 0x3f3f3f3f / 2) ans += min_cost[i];
			else fail = true, cant[i] = true;
		}
	}
	
	if (fail){
		puts("NO");
		for (int i = 1; i <= n; i ++)
			if (cant[id[i]]){
				cout << i << endl;
				return 0;
			}
	}
	else cout << "YES" << endl << ans << endl;
	return 0;
}
