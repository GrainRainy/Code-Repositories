#include <iostream>
#include <cstring>
#include <algorithm>

#define fi first
#define se second

using namespace std;
using LL = long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e5 + 100;
int n;
// basic things
int head[N], idx;
int headb[N << 1], idx; // new graph
struct node{
	int nxt, to;
}edge[N << 3];
// n * 2 refers to origin graph and n * 4 refers to new graph
int dist[N];
bool st[N];
priority_queue<PII, vector<PII>, greater<PII>> heap;
// shortest path
int timestamp, scc_cnt;
int dfn[N], low[N], id[N];
int stk[N], top;
int sze[N];
bool st[N];

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

void djikstra(){
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0, heap.push({0, 1});
	
	while (heap.size()){
		int distance = heap.top().fi;
		int ver = heap.top().se;
		
		if (st[ver]) continue;
		st[ver] = true;
		for (int i = headb[ver]; ~i; i = edge[i].nxt){
			int j = edge[i].to;
			if (dist[j] > dist[ver] + distance){
				dist[j] = dist[ver] + distance;
				heap.push({dist[j], j});
			}
		}
	}
}

void tarjan(int u){
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
			id[tmp] = scc_cnt;
			sze[scc_cnt] ++;
			st[tmp] = false;
		} while (tmp != u);
	}
}

int main(){
	memset(head, -1, sizeof head);
	memset(headb, -1, sizeof headb);
	// init 
	
	input(n);
	int tmpa, tmpb;
	for (int i = 1; i <= n; i ++){
		input(tmpa), input(tmpb);
		add(tmpa, tmpb);
	}
	// input
	for (int i = 1; i <= n; i ++){
		if (!dfn[i]) tarjan(i);
	}
	
	for (int i = 1; i <= n; i ++){
		for (int j = head[i]; ~j; j = edge[j].nxt){
			int t = edge[j].to;
			
		}
	}
}
