#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using IO::input;
using namespace std; 
const int N = 1e6 + 10;
int n, st, ed;
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int path[N], top, brc[N]; // path calculating
int siz[N], fa[N], f[N], dg[N]; // used for single dots

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u, int father) {
	fa[u] = father;
	int mxa = 0, mxb = 0, cnt = 0;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs(j, u);
		if (f[j] >= mxa) mxb = mxa, mxa = f[j];
		else if (f[j] > mxb) mxb = f[j];
	}
	f[u] = mxb + dg[u] - 1;
}

bool check(int step) {
	int tmp = 0, nd = 0;
	for (int i = 1; i < top; ++ i) {
		tmp = 0;
		for (int j = head[path[i]], k; ~j; j = edge[j].nxt) {
			k = edge[j].to;
			if (k != path[i + 1] and k != path[i - 1] and brc[i] + f[k] + 1 - (i != 1) > step)
				tmp ++;
		}
		nd += tmp, step -= tmp;
		if (step < 0 or nd > i) return false;
	}
	return true;
}

int main() {
	input(n), input(ed), input(st);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) {
		input(a), input(b);
		add(a, b), add(b, a);
		dg[a] ++, dg[b] ++;
	}
	dfs(ed, 0);
	int u = st;
	while(u) path[++ top] = u, u = fa[u];
	for (int i = top - 1; i; -- i) 
		brc[i] = brc[i + 1]+ dg[path[i]] - 1 - (path[i] != ed);
	int l = 0, r = N, mid;
	while (l < r) {
		mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
