#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		while (!isdigit(c)) c = getchar();
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
}
using IO::rd;
using namespace std;
const int N = 1e5 + 10;
int id, t, n, head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int siz[N], dep[N], f[N], hs[N], lhs[N];
bool ans[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dp(int u, int fa) {
	hs[u] = lhs[u] = 0, ans[u] = false;
	dep[u] = dep[fa] + 1, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		dp(j, u);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) lhs[u] = hs[u], hs[u] = j;
		else if (siz[j] > siz[lhs[u]]) lhs[u] = j;
	}
	if (siz[hs[u]] - (f[hs[u]] << 1) <= siz[u] - 1 - siz[hs[u]])
		f[u] = siz[u] - 1 >> 1;
	else f[u] = f[hs[u]] + siz[u] - 1 - siz[hs[u]];
}

inline int upd(int x, int y) { return siz[x] < siz[y] ? y : x; }
void move(int u, int fa, int premx) {
	int mx = upd(hs[u], premx);
	if (siz[mx] - (f[mx] << 1) <= n - dep[u] - siz[mx])
		ans[u] = (n & 1) == (dep[u] & 1);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		move(j, u, j == hs[u] ? upd(premx, lhs[u]) : upd(premx, hs[u]));
	}
}

int main() {
	rd(id), rd(t);
	while (t --) {
		rd(n); idx = 0;
		memset(head, -1, sizeof(int) * (n + 10));
		for (int i = 1, a, b; i < n; ++ i)
			rd(a), rd(b), add(a, b), add(b, a);
		dp(1, 0), move(1, 0, 0);
		putchar((f[1] << 1) + 1 == n ? '1' : '0');
		if (id != 3) for (int i = 2; i <= n; ++ i) putchar(ans[i] ? '1' : '0');
		putchar('\n');
	}
	return 0;
}
