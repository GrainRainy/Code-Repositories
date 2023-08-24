#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace std;
using namespace IO;

const int N = 2e5 + 10;
int n, x, y, sx[N], sy[N], col[N];
int head[N], idx;
struct Node { int nxt, to; } edge[N << 1];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u, int color) {
	col[u] = color;
	for (int i = head[u]; ~i; i = edge[i].nxt) 
		if (!(~col[edge[i].to])) dfs(edge[i].to, color ^ 1);
	return;
}

int main() {
	input(n);
	memset(head, -1, sizeof(int) * (n + 10));
	memset(col, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= n; ++ i) {
		input(x), input(y);
		if (sx[x]) add(sx[x], i), add(i, sx[x]), sx[x] = 0;
		else sx[x] = i;
		if (sy[y]) add(sy[y], i), add(i, sy[y]), sy[y] = 0;
		else sy[y] = i;
	}
	for (int i = 1; i <= n; ++ i) if (!(~col[i])) dfs(i, 0);
	for (int i = 1; i <= n; ++ i) putchar((col[i] ? 'r' : 'b'));
	return 0;
}
