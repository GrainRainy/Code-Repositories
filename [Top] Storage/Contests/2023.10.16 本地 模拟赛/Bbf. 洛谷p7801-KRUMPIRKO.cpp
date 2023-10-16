#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 20 + 10;
int n, l;
struct Node { 
	int a, c;
	bool operator < (const Node &t) const {
		return (double)a / c < (double)t.a / t.c;
	};
}a[N];
double st, sa, sc, ans = 1e9;

void dfs(int pos, int cnt, int lsa, int lsc) {
	if ((clock() - st) / CLOCKS_PER_SEC > 0.98) {
		printf("%.3lf\n", ans), exit(0);
	}
	if (cnt == l) {
		ans = min(ans, (double)lsc / lsa * (sc - lsc) / (sa - lsa));
		return;
	} else if (n - pos + 1 + cnt == l) {
		for (int i = pos; i <= n; ++ i) lsa += a[i].a, lsc += a[i].c;
		ans = min(ans, (double)lsc / lsa * (sc - lsc) / (sa - lsa));
		return;
	}
	dfs(pos + 1, cnt + 1, lsa + a[pos].a, lsc + a[pos].c);
	dfs(pos + 1, cnt, lsa, lsc);
}

int main() {
	freopen("krumpirko.in", "r", stdin);
	freopen("krumpirko.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	st = clock();
	cin >> n >> l;
	if (l > n >> 1) l = n - l;
	for (int i = 1; i <= n; ++ i) cin >> a[i].a, sa += a[i].a;
	for (int i = 1; i <= n; ++ i) cin >> a[i].c, sc += a[i].c;
	sort(a + 1, a + n + 1), dfs(1, 0, 0, 0);
	return printf("%.3lf\n", ans), 0;
}
