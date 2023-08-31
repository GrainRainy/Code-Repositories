#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
bool st[N];

void solve() {
	cin >> n;
	memset(st, 0, sizeof(bool) * (n + 10));
	for (int i = 1; i <= n; ++ i) {
		if (st[i]) continue;
		int tmp = i;
		while (tmp <= n) {
			cout << tmp << ' ';
			st[tmp] = true;
			tmp <<= 1;
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0; 
}
