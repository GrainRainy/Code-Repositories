#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, p[N];
char a[N];
bool st[N]; 

void solve() {
	cin >> a + 1, n = strlen(a + 1);
	memset(st, 0, sizeof(bool) * (n + 10));
	for (int i = 1, mid = 0, mr = 0; i <= n; ++ i) {
		p[i] = i < mr ? min(p[(mid << 1) - i], mr - i) : 1;
		while (i - p[i] and a[i + p[i]] == a[i - p[i]]) p[i] ++;
		if (i + p[i] > mr) mr = i + p[i], mid = i;
	}
	for (int i = n; i; -- i) {
		if (i + p[i] - 1 == n or i - p[i] + 1 == 1 and st[i + p[i] - 1])
			st[i] = true;
	}
	for (int i = 1; i <= n; ++ i) if (st[i]) cout << i << ' ';
	return cout << '\n', void();
}

int main() {
//	freopen("string.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
