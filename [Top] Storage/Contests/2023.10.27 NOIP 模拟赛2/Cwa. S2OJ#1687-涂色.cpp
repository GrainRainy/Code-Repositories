#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 2e5 + 10;
int n, k, ans, c[N], t[N], head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
int fa[N], siz[N], dep[N], hs[N], dfn[N], node[N], stamp;
int tree[N << 2];
#define l(x) ((x) << 1)
#define r(x) ((x) << 1 | 1)
#define mx(x) tree[x]
bool st[N];

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void dfs1(int u, int father, int depth) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	dfn[u] = ++ stamp, node[stamp] = u;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == father) continue;
		dfs1(v, u, depth + 1);
		siz[u] += siz[v];
		if (siz[v] > siz[hs[u]]) hs[u] = v;
	}
}

void modify(int u, int tl, int tr, int pos, int v) {
	if (tl == tr) return mx(u) += v, void();
	int mid = tl + tr >> 1;
	if (pos <= mid) modify(l(u), tl, mid, pos, v);
	else modify(r(u), mid + 1, tr, pos, v);
	mx(u) = max(mx(l(u)), mx(r(u)));
}

void calc(int u, bool kp) {
	if (!hs[u]) return kp ? modify(1, 1, k, c[u], 1) : void();
	modify(1, 1, k, c[u], 1);
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if ((v = edge[i].to) != fa[u] and v != hs[u]) calc(v, 0);
	calc(hs[u], 1);
	modify(1, 1, k, c[u], -1);
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) != fa[u] and v != hs[u]) {
			for (int j = dfn[v]; j < dfn[v] + siz[v]; ++ j)
				if (!st[c[node[j]]]) {
					modify(1, 1, k, c[node[j]], 1);
					st[c[node[j]]] = true;
				}
			for (int j = dfn[v]; j < dfn[v] + siz[v]; ++ j)
				st[c[node[j]]] = false;
		}
	}
	if (mx(1) > 1) t[c[u]] --;
	if (!kp) {
		for (int i = head[u], v; ~i; i = edge[i].nxt) {
			if ((v = edge[i].to) != fa[u]) {
				for (int j = dfn[v]; j < dfn[v] + siz[v]; ++ j)
					if (!st[c[node[j]]]) {
						modify(1, 1, k, c[node[j]], -1);
						st[c[node[j]]] = true;
					}
				for (int j = dfn[v]; j < dfn[v] + siz[v]; ++ j)
					st[c[node[j]]] = false;
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) cin >> c[i], t[c[i]] ++, head[i] = -1;
	for (int i = 1, a, b; i < n; ++ i) cin >> a >> b, add(a, b), add(b, a);
	dfs1(1, 0, 1), calc(1, 0);
	for (int i = 1; i <= k; ++ i) if (t[i]) ans ++;
	cout << ans << '\n';
	for (int i = 1; i <= k; ++ i) if (t[i]) cout << i << ' ';
	return cout << '\n', 0; 
}
