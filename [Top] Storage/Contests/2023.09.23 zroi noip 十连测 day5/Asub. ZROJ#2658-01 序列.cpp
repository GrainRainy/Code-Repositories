#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, cnt;
string ori, cp, ans = "2";

namespace sub2 {
	int as[N];
	void solve() {
		for (int i = n; m; -- i, -- m) as[i] = m & 1;
		for (int i = 1; i <= n; ++ i) cout << as[i];
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> ori;
	for (auto t : ori) cnt += t == '?';
	if (cnt == n) return sub2::solve(), 0;
	for (int s = 0; s < 1 << cnt; ++ s) {
		cp = ori;
		for (int i = 1, j = 0; i <= cnt; ++ i, ++ j) {
			while (ori[j] != '?') j ++;
			if ((s >> i - 1) & 1) cp[j] = '1';
			else cp[j] = '0';
		}
		int res = 0;
		for (int i = 1; i < cp.size(); ++ i) 
			res += cp[i] != cp[i - 1];
		if (res == m and cp < ans) ans = cp;
	}
	if (ans == "2") cout << "-1\n";
	else cout << ans << '\n';
	return 0;
}
