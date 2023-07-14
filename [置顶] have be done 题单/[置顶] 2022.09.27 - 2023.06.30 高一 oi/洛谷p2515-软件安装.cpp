#include <cstring>
#include <iostream>
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

const int N = 100 + 10;
const int M = 500 + 10;
int n, m;
int w[N], v[N], d[N];
// basis
int head[N], idx;
struct node{
	int nxt, to;
}edge[M << 1];
// graph
int timestamp, scc_cnt;
int stk[N], top;
bool st[N];
int dfn[N], low[N], id[N];
int sccw[N], sccv[N];
// tarjan
int indg[N];
int headb[N], idxb;
int f[N][M];
// dp

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
}

inline void addb(int a, int b){
	edge[++ idx].nxt = headb[a];
	edge[idx].to = b;
	headb[a] = idx;
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
			sccw[scc_cnt] += w[tmp];
			sccv[scc_cnt] += v[tmp];
		} while (tmp != u);
	}
	return;
}

inline void dp(int u){
	for (int i = sccw[u]; i <= m; ++ i)	
		f[u][i] = sccv[u];
	// init
	for (int i = headb[u]; ~i; i = edge[i].nxt){
		int j = edge[i].to;
		dp(j);
		for (int k = m - sccw[u]; k >= 0; -- k)
			for (int l = 0; l <= k; ++ l){
				f[u][k + sccw[u]] = max(f[u][k + sccw[u]], f[u][k + sccw[u] - l] + f[j][l]);
			}
	}
}

int main(){
	memset(head, -1, sizeof head);
	memset(headb, -1, sizeof headb);
	// graph init
	
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) input(w[i]);
	for (int i = 1; i <= n; ++ i) input(v[i]);
	for (int i = 1; i <= n; ++ i){
		int tmp; input(tmp);
		if (tmp) add(tmp, i);
	}
	// input and add
	
	for (int i = 1; i <= n; ++ i)
		if (!dfn[i]) tarjan(i);
	
	for (int i = 1; i <= n; ++ i)
		for (int j = head[i]; ~j; j = edge[j].nxt){
			int t = edge[j].to;
			if (id[i] != id[t]){
				addb(id[i], id[t]);
				indg[id[t]] ++;
			}
		}
	
	int root = scc_cnt + 1;
	sccw[root] = sccv[root] = 0;
	for (int i = 1; i <= scc_cnt; ++ i)
		if (!indg[i]) addb(root, i);
	// change root and then dp from the root
	dp(root);
	
	int ans = -1;
	for (int i = 0; i <= m; ++ i) ans = max(ans, f[root][i]);
	cout << ans << endl;
	
//	cout << id[1] << " " << id[2] << " " << id[3] << endl;
//	for (int i = 1; i <= scc_cnt + 1; ++ i){
//		cout << i << " -> ";
//		for (int j = headb[i]; ~j; j = edge[j].nxt)
//			cout << edge[j].to << " ";
//		cout << endl;
//	}
	cout << endl;
	return 0;
}
