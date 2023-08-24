#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define __DEBUG__ puts("yes");

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 3e5 + 10;
const int LOGN = 19;

int n, u, v;
int path[N];
int head[N], idx;
struct Node {
	int nxt, to;
}edge[N << 1];
int depth[N], fa[N][LOGN + 10];
queue<int> q;
int sum[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void init(int u) {
	memset(depth, 0x3f, sizeof depth);
	depth[0] = 0, depth[u] = 1;
	q.push(u);
	while (q.size()) {
		int j = q.front(); q.pop();
		for (int i = head[j]; ~i; i = edge[i].nxt) {
			int to = edge[i].to;
			if (depth[to] > depth[j] + 1){
				depth[to] = depth[j] + 1;
				q.push(to);
				fa[to][0] = j;
				for (int k = 1; k <= LOGN; k ++) 
					fa[to][k] = fa[fa[to][k - 1]][k - 1];
			}
		}
	}
}

int query(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	for (int k = LOGN; k >= 0; k --)
		if (depth[fa[u][k]] >= depth[v]) u = fa[u][k];
	if (u == v) return u;
	for (int k = LOGN; k >= 0; k --)
		if (fa[u][k] ^ fa[v][k]) {
			u = fa[u][k], v = fa[v][k];
		}
	return fa[u][0];
}

void dfs(int u) {
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == fa[u][0]) continue;
		dfs(j);
		sum[u] += sum[j];
	}
	return;
}

int main() {
	memset(head, -1, sizeof head);
	
	input(n);
	for (int i = 1; i <= n; ++ i) input(path[i]);
	for (int i = 1; i < n; ++ i) {
		input(u), input(v);
		add(u, v), add(v, u);
	}
	
	init(1);
	
	for (int i = 1; i <= n - 1; ++ i) {
		int lca = query(path[i], path[i + 1]);
		sum[path[i]] ++, sum[path[i + 1]] ++;
		sum[lca] --;
		sum[fa[lca][0]] --;
	}
	dfs(1);
	for (int i = 2; i <= n; i ++) {
		sum[path[i]] --;	
	}
	
	for (int i = 1; i <= n; i ++) output(sum[i]);
	return 0;
}
