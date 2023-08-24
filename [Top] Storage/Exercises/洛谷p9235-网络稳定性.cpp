#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

#define __DEBUG__ puts("__DEBUG__");

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
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
const int LOGN = 17;
const int M = 3e5 + 10;
 
int n, m, q;
int x, y, z;
// basis 
int idx;
struct Node{
	int a, b, w;
	bool operator > (const Node &t) const {
		return w > t.w;
	}
}edge[M << 1];

int headb[N], idxb;
struct Nodeb {
	int nxt, to, w;
}edgeb[M << 1];
// graphs
int father[N]; // union and search 
int depth[N], fa[N][LOGN + 10], minn[N][LOGN + 10]; 
// LCA 

inline void addb(int a, int b, int c) {
	edgeb[++ idxb].nxt = headb[a];
	edgeb[headb[a] = idxb].to = b;
	edgeb[idxb].w = c;
}

int find(int u) {
	if (father[u] != u) return father[u] = find(father[u]);
	return u;
}

void kruskal() {
	sort(edge + 1, edge + 1 + idx, greater<Node>());
	
	for (int i = 1; i <= n; ++ i) father[i] = i;
	for (int i = 1; i <= idx; ++ i) {
		if (find(edge[i].a) != find(edge[i].b)) {
			father[find(edge[i].a)] = find(edge[i].b);
			addb(edge[i].a, edge[i].b, edge[i].w);
			addb(edge[i].b, edge[i].a, edge[i].w);
		}
	}
}

void init(int root) {
	queue<int> q;
	depth[root] = 1, depth[0] = 0;
	q.push(root);
	
	while (q.size()) {
		int t = q.front(); q.pop();
		for (int i = headb[t]; ~i; i = edgeb[i].nxt) {
			int j = edgeb[i].to;
			if (depth[j] > depth[t] + 1) {
				depth[j] = depth[t] + 1;
				q.push(j);
				fa[j][0] = t, minn[j][0] = edgeb[i].w;
				for (int k = 1; k <= LOGN; ++ k) {
					fa[j][k] = fa[fa[j][k - 1]][k - 1];
					minn[j][k] = min(minn[j][k - 1], minn[fa[j][k - 1]][k - 1]);
				}
			}
		}
	}
}

int query(int a, int b) {
	int ans = 0x3f3f3f3f;
	if (depth[a] < depth[b]) swap(a, b);
	for (int k = LOGN; k >= 0; -- k) {
		if (depth[fa[a][k]] >= depth[b]) {
			ans = min(minn[a][k], ans);
			a = fa[a][k];
		}
	}
	if (a == b) return ans;
	for (int k = LOGN; k >= 0; -- k) {
		if (fa[a][k] ^ fa[b][k]) {
			ans = min({ans, minn[a][k], minn[b][k]});
			a = fa[a][k], b = fa[b][k];
		}
	}
	ans = min({ans, minn[a][0], minn[b][0]});
	return ans;
}

int main() {
	memset(headb, -1, sizeof headb);
	
	input(n), input(m), input(q);
	for (int i = 1; i <= m; ++ i) {
		input(x), input(y), input(z);
		edge[++ idx] = {x, y, z};
	}
	kruskal();
	
	memset(depth, 0x3f, sizeof depth);
	for (int i = 1; i <= n; i ++) {
		if (depth[i] != 0x3f3f3f3f) continue;
		init(i);
	}
	
	while (q --) {
		input(x), input(y);
		if (find(x) != find(y)) puts("-1");
		else output(query(x, y));
	}
	return 0;
}
