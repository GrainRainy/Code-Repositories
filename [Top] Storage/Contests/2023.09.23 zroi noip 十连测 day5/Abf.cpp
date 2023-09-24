#include <bits/stdc++.h>
using namespace std;
const int N = 20 + 10;
int n, m, cnt;
string ori, cp, ans = "2";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> ori;
	for (int m = 1; m <= n; ++ m) {
		ans = "2", cnt = 0;
		for (auto t : ori) cnt += t == '?';
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
		if (ans == "2") cout << "-1 ";
		else cout << ans << ' ';
		cout << m << '\n';
	}
	return 0;
}
