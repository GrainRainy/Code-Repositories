#include <bits/stdc++.h>
using namespace std;
using LL = long long; 
const int N = 1e4 + 10;
int n, head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
int dg[N];
LL ans;
char s[N];

inline void add(int a, int b) {
	cout << a << ' ' << b << '\n';
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void solve() {
	cin >> n >> s + 1, ans = 0;
	memset(dg, 0, sizeof dg);
	for (int i = 1; i <= n; ++ i) 
		if (s[i] == '1') dg[i + (i & -i)] ++;
	for (int i = 1; i <= n; ++ i) 
		if (!dg[i] and s[i] == '1') ans ++;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
