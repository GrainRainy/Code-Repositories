#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long;
const int N = 1e6 + 10;
int n, a[N], b[N], st[N];
string m;
vector<int> cir[N];
ULL g, cnt;

void dfs(int u) {
	if (st[a[u]]) return;
	st[a[u]] = st[u];
	cir[st[u]].push_back(a[u]);
	dfs(a[u]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i], b[i] = a[i];
	cin >> m; m[m.size() - 1] -= 1;
	for (int i = 1; i <= n; ++ i) 
		if (!st[i]) st[i] = i, cir[i].push_back(i), dfs(i);
	for (int i = 1; i <= n; ++ i) {
		if (!cir[i].size()) continue;
		if (!g) g = cir[i].size();
		else g = g * cir[i].size() / __gcd(g, cir[i].size());
	}
	for (auto t : m) cnt = (cnt * 10 % g + (t - '0')) % g;
	for (int i = 1; i <= n; ++ i)
		for (int j = 0; j < cir[i].size(); ++ j)
			b[cir[i][j]] = a[cir[i][(j + cnt) % cir[i].size()]];
	for (int i = 1; i <= n; ++ i) cout << b[i] << ' ';
	return cout << '\n', 0;
}
