#include <bits/stdc++.h>
#define enter putchar('\n')
#define endl '\n'
#define fi first
#define se second

namespace IO {
	#ifdef __LINUX__
	#define getchar() getchar_unlocked()
	#define putchar(a) putchar_unlocked(a)
	#endif
	
	#ifdef __WINDOWS__
	#define getchar() _getchar_nolock()
	#define putchar(a) _putchar_nolock()
	#endif
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar(); bool mx = false;
		for (; !isdigit(c); c = getchar()) mx |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (mx) x = -x;
	}
	template <typename T, typename... Args> 
	void input(T &x, Args&... args) { input(x), input(args...); }
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
	template <typename T, typename ...Args>
	void output(T x, char ch = ' ', Args... args) {
		output(x, ch);
		output(args...);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

const int N = 6e3 + 10;
int t, testId;
int n, d, c, x[N], y[N];
int head[N], idx;
struct Node { int nxt, to; } edge[N * N];
int timestamp, sccCnt, stk[N], top;
bool st[N];
int dfn[N], low[N], id[N], cnt[N];
// tarjan
bool vis[N], gph[N][N];
int mx[N], indg[N];
int ans;
// topsort 
int headb[N], idxb;
struct nodeb{ int nxt, to; } edgeb[N * N];

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

inline void ADD(int a, int b){
	edgeb[++ idxb].nxt = headb[a];
	edgeb[headb[a] = idxb].to = b;
}

inline void tarjan(int u){
	dfn[u] = low[u] = ++ timestamp;
	stk[++ top] = u, st[u] = true;
	for (int i = head[u], j; ~i; i = edge[i].nxt){
		j = edge[i].to;
		if (!dfn[j]){ tarjan(j); low[u] = min(low[u], low[j]); }
		else if (st[j]) low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u]){
		int tmp;
		sccCnt ++;
		do {
			tmp = stk[top --];
			st[tmp] = false;
			id[tmp] = sccCnt;
			cnt[sccCnt] ++;
		} while (tmp != u);
	}
}

void dfs(int u){
	vis[u] = true;
	for (int i = 1; i <= sccCnt; ++ i) {
		if (!gph[u][i]) continue;
		if (!vis[i]) dfs(i);
		indg[i] ++;
	}
	return;
}

int topsort(int u){
	queue<int> q; q.push(u);
	mx[u] = cnt[u];
	
	while(q.size()){
		int x = q.front(); q.pop();
		ans = max(ans, mx[x]);
		for (int i = 1; i <= sccCnt; ++ i) {
			if (!gph[x][i]) continue;
			indg[i] --;
			mx[i] = max(mx[i], mx[x] + cnt[i]); 
			if (!indg[i]) q.push(i);
		}
	}
	return ans;
}

int dfs2(int u) {
	int disu = 0;
	for (int i = 1; i <= sccCnt; ++ i) {
		if (!gph[u][i]) continue;
		disu = max(disu, dfs2(i));
	}
	return disu + cnt[u];
}

inline bool check(int a, int b) { return (y[b] <= y[a] + d - abs(x[a] - x[b])); }

void solve() {	
	ans = sccCnt = top = timestamp = idx = idxb = 0;
	input(n, d, c);
	memset(head, -1, sizeof head);
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	memset(id, 0, sizeof id);
	memset(cnt, 0, sizeof cnt);
	memset(st, 0, sizeof st);
	memset(mx, 0, sizeof mx);
	memset(vis, 0, sizeof vis);
	for (int i = 0; i <= n; ++ i)
		for (int j = 0; j <= n; ++ j)
			gph[i][j] = 0;
	
	for (int i = 1; i <= n; ++ i) input(x[i], y[i]);
	for (int i = 1; i <= n; ++ i)
		for (int j = i + 1; j <= n; ++ j) {
			if (i != j and check(i, j)) add(i, j);
			if (i != j and check(j, i)) add(j, i);
		}
	
	for (int i = 1; i <= n; i ++) if (!dfn[i]) tarjan(i);
	
	for (int i = 1; i <= n; i ++)
		for (int j = head[i], t; ~j; j = edge[j].nxt){
			t = edge[j].to;
			if (id[i] != id[t]) gph[id[i]][id[t]] = true;
		}
	dfs(id[c]);
	output(topsort(id[c]), '\n');
	return;
}

int main() {
	input(t, testId);
	while (t -- ) solve();
	return 0;
}
