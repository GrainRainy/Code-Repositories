#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int n, m, w[N], fa[N];
struct Node { int a, b, v; }e[N * N];
long long ans;

int find (int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> w[i];
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			if (i != j) e[++ m] = {i, j, w[i] ^ w[j]};
	sort(e + 1, e + m + 1, [](Node &a, Node &b) { return a.v < b.v; });
	for (int i = 1; i <= n; ++ i) fa[i] = i;
	for (int i = 1, a, b; i <= m; ++ i) {
		a = find(e[i].a), b = find(e[i].b);
		if (a == b) continue;
		fa[a] = b, ans += e[i].v;
	}
	return cout << ans << '\n', 0;
}
