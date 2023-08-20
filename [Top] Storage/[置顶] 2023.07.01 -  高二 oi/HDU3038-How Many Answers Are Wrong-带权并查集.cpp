#include <iostream>
using namespace std;
const int N = 2e5 + 10;
int n, m, fa[N], w[N], ans;

int find(int u) {
    if (u == fa[u]) return u;
    int tmp = fa[u];
    fa[u] = find(fa[u]);
    w[u] += w[tmp];
    return fa[u];
}

void merge(int x, int y, int v) {
	int fx = find(x), fy = find(y);
	if (fx == fy) ans += (v != w[y] - w[x]);
	else fa[fy] = fx, w[fy] = -w[y] + v + w[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (cin >> n >> m) {
		ans = 0;
		for (int i = 1; i <= n; ++ i) fa[i] = i, w[i] = 0;
		for (int i = 1, l, r, v; i <= m; ++ i) {
			cin >> l >> r >> v;
			merge(l - 1, r, v);
		}
		cout << ans << '\n';
	}
	return 0;
}
