#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;
int n, m, head[N], etp, ans;
struct Node { int nxt, to, w; }edge[N << 1];
int p[N], fa[N], dep[N], w[N], siz[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

inline void add(int a, int b, int w) {
	edge[++ etp] = {head[a], b, w};
	head[a] = etp;
}

void dec(int &x, int y) { if ((x -= y) < 0) x += MOD; }
void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void dfs(int u, int father, int depth) {
	siz[u] = 1, fa[u] = father, dep[u] = depth;
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if ((v = edge[i].to) != father) {
			w[v] = edge[i].w, dfs(v, u, depth + 1);
			upd(ans, 1ll * w[v] * (n - siz[v]) % MOD * siz[v] % MOD);
			siz[u] += siz[v];
		}
}

void mfy(int a, int b) {
	while (a != b) {
		if (dep[a] < dep[b]) swap(a, b);
		dec(ans, (long long)(w[a] - floor(sqrt(w[a] * 1.0))) * siz[a] % MOD * (n - siz[a]) % MOD);
		if ((w[a] = sqrt(w[a])) == 1) p[a] = p[fa[a]];
		a = fa[a], a = find(a), b = find(b);
	}
}

int main() {
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i) p[i] = i, head[i] = -1;
	for (int i = 1, a, b, w; i < n; ++ i)
		rd(a), rd(b), rd(w), add(a, b, w), add(b, a, w);
	dfs(1, 0, 1), ot(ans);
	for (int i = 1, a, b; i <= m; ++ i)
		rd(a), rd(b), mfy(a, b), ot(ans);
	return 0;
}
