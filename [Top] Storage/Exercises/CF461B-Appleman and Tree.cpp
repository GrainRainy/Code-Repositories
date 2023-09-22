#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
int n, head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
bool col[N];
long long f[N][2];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u, int fa) {
	f[u][col[u]] = 1;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == fa) continue;
		dfs(v, u);
		f[u][1] = (f[u][1] * (f[v][0] + f[v][1]) % MOD + f[u][0] * f[v][1] % MOD) % MOD;
		f[u][0] = f[u][0] * (f[v][1] + f[v][0]) % MOD;
	}
}

int main() {
	rd(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 2, a; i <= n; ++ i) {
		rd(a), a ++;
		add(a, i), add(i, a);
	}
	for (int i = 1; i <= n; ++ i) rd(col[i]);
	dfs(1, 0);
	return cout << f[1][1] << '\n', 0;
}
