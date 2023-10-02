#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e5 + 10;
int n, m, w[N], ptp, head[N], idx;
struct Node { int nxt, to; }edge[N];
unordered_map<string, int> mp;
int fa[N], dep[N], siz[N], dfn[N], stamp, nw[N], pre[N];
vector<int> dary[N];
string s;

struct BIT {
	int tr[N];
	inline void add(int p, int v) { while (p <= n) tr[p] += v, p += p & -p; }
	int query(int r) { int res = 0; while (r) res += tr[r], r -= r & -r; return res; }
}t;

struct Query {
	int d, l, r, id;
	bool operator < (const Query &t) const { return d ^ t.d ? d < t.d : r < t.r; }
}q[N];
int ans[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u, int depth) {
	if (!dary[depth].size()) dary[depth].push_back(0);
	siz[u] = 1, dep[u] = depth;
	dfn[u] = ++ stamp, nw[stamp] = w[u], dary[dep[u]].push_back(stamp);
	for (int i = head[u], v; ~i; i = edge[i].nxt) 
		dfs(v = edge[i].to, depth + 1), siz[u] += siz[v];
}

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	cin >> n;
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= n; ++ i) {
		cin >> s >> fa[i];
		if (mp.find(s) == mp.end()) mp[s] = ++ ptp;
		w[i] = mp[s], add(fa[i], i);
	}
	dfs(0, 0);
	cin >> m;
	for (int i = 1, v, k, d, l, r; i <= m; ++ i) {
		cin >> v >> k;
		d = dep[v] + k;
		l = lower_bound(dary[d].begin(), dary[d].end(), dfn[v]) - dary[d].begin();
		r = upper_bound(dary[d].begin(), dary[d].end(), dfn[v] + siz[v] - 1) - dary[d].begin() - 1;
		q[i] = {d, l, r, i};
	}
	sort(q + 1, q + m + 1);
	int p = 1;
	for (int i = 1; i <= m; ++ i) {
		if (!dary[q[i].d].size()) continue;
		while (p <= q[i].r) {
			if (pre[nw[dary[q[i].d][p]]]) t.add(pre[nw[dary[q[i].d][p]]], -1);
			pre[nw[dary[q[i].d][p]]] = p, t.add(p, 1), p ++;
		}
		ans[q[i].id] = t.query(q[i].r) - t.query(q[i].l - 1);
		if (q[i].d != q[i + 1].d) {
			for (int i = 1; i <= ptp; ++ i) 
				if (pre[i]) t.add(pre[i], -1), pre[i] = 0;
			p = 1;
		}
	}
	for (int i = 1; i <= m; ++ i) cout << ans[i] << '\n';
	return 0;
}
