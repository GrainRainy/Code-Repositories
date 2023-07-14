#include <iostream>
#include <cstring>
#include <algorithm>

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

const int N = 5e5 + 10;
int n, q, root;
int x, k;
LL ans, SaveAns;

int head[N], idx;
struct Node {
	int nxt, to;
}edge[N << 1];

int dep[N], siz[N], fa[N], hs[N];
int stamp, dfn[N], id[N], top[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int depth) {
	dep[u] = depth, siz[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == fa[u]) continue;
		dfs1(j, depth + 1);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
	return;
}

void dfs2(int u, int Top) {
	dfn[u] = ++ stamp, id[stamp] = u, top[u] = Top;
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		if (j == fa[u] or j == hs[u]) continue;
		dfs2(j, j);
	}
	return;
}

int find(int x, int k){
	while (k >= dfn[x] - dfn[top[x]] + 1 && x != root) {
		k -= dfn[x] - dfn[top[x]] + 1;
		x = fa[top[x]];
	}
	return id[dfn[x]-k];
}

#define ui unsigned int
ui s;
inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}

int main() {
	memset(head, -1, sizeof head);
	
	input(n), input(q), input(s);
	for (int i = 1; i <= n; i ++) {
		input(fa[i]);
		if (!fa[i]) root = i;
		else add(fa[i], i), add(i, fa[i]);
	}
	
	dfs1(root, 1);
	dfs2(root, root);

	for (int i = 1; i <= q; i ++) {
		x = (get(s) ^ SaveAns) % n + 1;
		k = (get(s) ^ SaveAns) % dep[x];
		SaveAns = find(x, k);
		ans ^= SaveAns * i;
	}
	cout << ans << '\n';
	return 0;
}
