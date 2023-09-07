#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
const int L = 5e2 + 10;
int n, k, head[N << 1], idx, nd;
int tr[N * L][26], ed[N * L], dep[N * L], cson[N * L], tot = 1;
struct Node { int nxt, to, w; }edge[N << 1];
int f[N << 1][N << 1], siz[N << 1];
string s;

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void insert(const string &s) {
	int p = 1;
	for (auto t : s) {
		if (!tr[p][t - 'a'])
			tr[p][t - 'a'] = ++ tot, cson[p] ++;
		p = tr[p][t - 'a'];
	}
	ed[p] ++;
}

void compress(int u, int depth, int fa, int nfa) {
	dep[u] = depth;
	if (cson[u] > 1 or ed[u] or u == 1) {
		add(nfa, ++ nd, dep[u] - dep[fa]);
		siz[nd] += ed[u];
		fa = u, nfa = nd;
	}
	for (int i = 0; i < 26; ++ i)
		if (tr[u][i]) compress(tr[u][i], depth + 1, fa, nfa);
}

void dp(int u) {
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		dp(v = edge[i].to);
		for (int j = 1; j <= min(k, siz[v]); ++ j)
			f[v][j] += j * (j - 1) / 2 * edge[i].w;
		for (int j = min(siz[u], k); ~j; -- j)
			for (int a = min(k - j, siz[v]); a; -- a)
				f[u][j + a] = max(f[u][j + a], f[u][j] + f[v][a]);
		siz[u] += siz[v];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	memset(head, -1, sizeof head);
	for (int i = 1; i <= n; ++ i) cin >> s, insert(s);
	compress(1, 0, 0, 0), dp(1);
	return cout << f[1][k] << '\n', 0;
}
