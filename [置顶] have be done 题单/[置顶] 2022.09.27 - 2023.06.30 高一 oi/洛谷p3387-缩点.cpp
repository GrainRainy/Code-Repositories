#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

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
const int M = 1e5 + 10;

int n, m;
int dw[N]; // dots' weights
// basic things
int head[N], idx;
struct node{
	int nxt, to;
}edge[M];
// graph
int timestamp, scc_cnt;
int stk[N], top;
bool st[N];
int dfn[N], low[N], id[N];
int cnt[N];
// tarjan
int headb[N], idxb;
struct nodeb{
	int nxt, to;
}edgeb[M];
int indg[N], outdg[N];
int dist[N];
int ans;
// topsort

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

inline void ADD(int a, int b){
//	cout << a << " -> " << b << endl;
	edgeb[++ idxb].to = b;
	edgeb[idxb].nxt = headb[a];
	headb[a] = idxb;
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
		do {
			tmp = stk[top --];
			st[tmp] = false;
			id[tmp] = scc_cnt;
			cnt[scc_cnt] += dw[tmp];
		} while (tmp != u);
	}
}

inline void topsort(){
	queue<int> q;
	for (int i = 1; i <= scc_cnt; i ++){
		if (!indg[i]){
			q.push(i);
			dist[i] = cnt[i];
			ans = max(dist[i], ans);
		}
	}
	
	while (q.size()){
		auto t = q.front(); q.pop();
		
		for (int i = headb[t]; ~i; i = edgeb[i].nxt){
			int j = edgeb[i].to;
			indg[j] --;
			if (dist[j] < dist[t] + cnt[j]){
				dist[j] = dist[t] + cnt[j];
				ans = max(ans, dist[j]);
			}
			if (!indg[j]) q.push(j);
		}
	}
}

int main(){
	memset(head, -1, sizeof head);
	memset(headb, -1, sizeof headb);
	// init graph
	
	input(n), input(m);
	for (int i = 1; i <= n; i ++)
		input(dw[i]);
	for (int i = 1; i <= m; i ++){
		int a, b; input(a), input(b);
		add(a, b);
	}
	// input
	for (int i = 1; i <= n; i ++)
		if (!dfn[i]) tarjan(i);
	
	for (int i = 1; i <= n; i ++)
		for (int j = head[i]; ~j; j = edge[j].nxt){
			int t = edge[j].to;
			if (id[i] != id[t]){
				ADD(id[i], id[t]);
				indg[id[t]] ++, outdg[id[i]] ++;
			}
		}
	topsort();
	cout << ans << endl;
	
//	for (int i = 1; i <= scc_cnt; i ++)
//	cout << cnt[1] << " " << cnt[2] << " " << cnt[3] << " " << cnt[4] << " " << cnt[5] << endl;
	return 0;
}
