#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 2e5 + 10;
int n, m, q, l, r, x;
string s;
int tot, pmx, rmx, w[N], fa[N], tree[N];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void add(int x, int v) { while (x <= n) tree[x] += v, x += x & -x; }
int query(int r) {
	int res = 0;
	while (r) res += tree[r], r -= r & -r;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q >> s;
	for (int i = 1; i <= n + 1; ++ i) fa[i] = i;
	for (int i = 1, p; i <= m; ++ i) {
		cin >> l >> r;
		p = l;
		while ((p = find(p)) <= r) {
			w[p] = ++ rmx;
			fa[p] = find(p + 1);
		}
	}
	pmx = rmx;
	for (int i = 1; i <= n; ++ i) {
		if (!w[i]) w[i] = ++ rmx;
		if (s[i - 1] == '1') tot ++, add(w[i], 1);
	}
	while (q --) {
		cin >> x;
		if (s[x - 1] == '1') s[x - 1] = '0', tot --, add(w[x], -1);
		else s[x - 1] = '1', tot ++, add(w[x], 1);
		int t = min(pmx, tot);
		cout << t - query(t) << '\n';
	}
	return 0;
}
