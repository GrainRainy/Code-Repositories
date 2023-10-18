#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
const int MOD = 998244353;
int n, m, head[N], idx;
struct Node { int nxt, to, w; }edge[N];
int dfn[N], stamp, low[N], id[N], siz[N], scctot, stk[N], top;
vector<pair<int, int>> g[N];
vector<int> ary[N];
int dg[N], len[N], ans[N], jgval;
bool st[N], jg = true;

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

void tarjan(int u) {
	low[u] = dfn[u] = ++ stamp, stk[++ top] = u, st[u] = true;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if (!dfn[v = edge[i].to]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (st[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		scctot ++;
		int tmp;
		do {
			tmp = stk[top --];
			id[tmp] = scctot;
			siz[scctot] ++;
			st[tmp] = false;
		} while (dfn[tmp] != low[tmp]);
	}
}

bool cmp(vector<int> a, vector<int> b) { // b smaller ? 
	if (a.size() ^ b.size()) return a.size() < b.size(); 
	for (int i = a.size() - 1; ~i; -- i)
		if (a[i] ^ b[i]) return a[i] > b[i];
	return false;
}

void topsort(int u) {
	st[u] = true;
	if (siz[u] > 1) return len[u] = -1, void();
	int nxtw = 0;
	for (auto v : g[u]) {
		if (!st[v.first]) topsort(v.first);
		if (len[v.first] < 0 or len[u] < 0) len[u] = -1;
		else if (len[v.first] + 1 > len[u]) {
			len[u] = len[v.first] + 1;
			if (!jg) ary[u] = ary[v.first];
			ans[u] = ((LL)ans[v.first] * 29 % MOD + v.second) % MOD;
			nxtw = v.second;
		} else if (!jg and cmp(ary[u], ary[v.first])) {
			ary[u] = ary[v.first], nxtw = v.second;
			ans[u] = ((LL)ans[v.first] * 29 % MOD + v.second) % MOD;
		}
	}
	ary[u].push_back(nxtw);
}

int main() {
	freopen("watcher.in", "r", stdin);
	freopen("watcher.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b, c; i <= n; ++ i) {
		cin >> a >> b >> c, add(a, b, c);
		if (!jgval) jgval = c;
		else jg &= (c == jgval);
	}
	for (int i = 1; i <= n; ++ i) if (!dfn[i]) tarjan(i);
	for (int u = 1; u <= n; ++ u)
		for (int i = head[u], v; ~i; i = edge[i].nxt)
			if (id[v = edge[i].to] != id[u]) 
				g[id[u]].push_back({id[v], edge[i].w}), dg[id[v]] ++;
	memset(st, 0, sizeof(int) * (n + 10));
	for (int i = 1; i <= scctot; ++ i) if (!dg[i]) topsort(i);
	for (int i = 1; i <= n; ++ i) {
		if (len[id[i]] < 0) cout << "Infinity\n";
		else cout << (LL)ans[id[i]] * 29 % MOD << '\n';
	}
	return 0;
}
