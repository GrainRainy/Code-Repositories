#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e3 + 10;
int n, m, a[N], top;
struct Node {
	int a, b, w;
	bool operator < (const Node &t) const { return w < t.w; }
}p[N * N];
bool st[N];
LL ans;

int main() {
//	freopen("ex_data3.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			if (i != j) p[++ top] = {i, j, abs(a[i] - a[j])};
	sort(p + 1, p + top + 1);
	for (int i = 1, j = 1; i <= m; ++ i) {
		while (st[p[j].a] or st[p[j].b]) j ++;
		cout << p[j].a << ' ' << p[j].b << '\n';
		ans += p[j].w, st[p[j].a] = st[p[j].b] = true, j ++;
	}
	return cout << ans << '\n', 0;
}
