#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
int n, m, fa[N];
LL val[N];
bool f;

int find(int x) {
	if (fa[x] == x) return x;
	int tmp = fa[x];
	fa[x] = find(fa[x]);
	val[x] += val[tmp];
	return fa[x];
}

void merge(int x, int y, int w) {
	int fx = find(x), fy = find(y);
	if (fx == fy) f |= (w != val[y] - val[x]);
	else fa[fy] = fx, val[fy] = w + val[x] - val[y];
}

void solve() {
	cin >> n >> m; f = false;
	for (int i = 1; i <= n; ++ i) fa[i] = i, val[i] = 0;
	for (int i = 1, a, b, w; i <= m; ++ i)
		cin >> a >> b >> w, merge(a, b, w);
	return cout << (f ? "NO" : "YES") << '\n', void();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
