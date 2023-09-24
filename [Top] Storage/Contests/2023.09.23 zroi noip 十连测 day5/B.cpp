#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e3 + 10;
const int MOD = 998244353;
int n, m, fa[N], head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
LL p[N], ans;

inline void upd(LL &a, LL b) { a += b; if (a >= MOD) a -= MOD; }

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

namespace sub1 {
	int d[N];
	bool st[N];
	int calc(int u, int mx) {
		int res = d[u] >= mx;
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			if ((j = edge[i].to) == fa[u]) continue;
			res += calc(j, max(mx, d[u]));
		}
		return res;
	}
	
	void dfs(int pos) {
		if (pos == n + 1) return upd(ans, p[calc(1, 0)]);
		for (int i = 1; i <= n; ++ i) 
			if (!st[i]) {
				st[i] = true, d[pos] = i;
				dfs(pos + 1);
				st[i] = false, d[pos] = 0;
			}
	}
}

namespace sub2 {
	int dg[N];
	bool jd = true;
	void solve () {
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	p[0] = 1, p[1] = m;
	memset(head, -1, sizeof head);
	for (int i = 2; i <= n; ++ i) {
		cin >> fa[i], add(fa[i], i);
		sub2::dg[fa[i]] ++, sub2::dg[i] ++;
		p[i] = p[i - 1] * m % MOD;
		if (sub2::dg[fa[i]] > 2 or sub2::dg[i] > 2)
			sub2::jd = false;
	}
	sub1::dfs(1);
	return cout << ans << '\n', 0;
}
