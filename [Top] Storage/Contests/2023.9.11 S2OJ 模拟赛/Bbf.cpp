#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, b[N], a[N], ck[N];

namespace sub1 {
	bool dfs(int pos) {
		if (pos > n) {
			for (int i = 1; i <= n; ++ i) ck[i] = 0;
			for (int i = 1, mn = 0x3f3f3f3f; i <= n; ++ i) {
				mn = min(a[i], mn);
				if (mn == b[i]) ck[i] ++;
			}
			for (int i = n, mn = 0x3f3f3f3f; i; -- i) {
				mn = min(a[i], mn);
				if (mn == b[i]) ck[i] ++;
			}
			for (int i = 1, mn = 0x3f3f3f3f; i <= n; ++ i)
				if (!ck[i]) return false;
			return true;
		}
		for (int i = 1; i <= n; ++ i) {
			a[pos] = b[i];
			if (dfs(pos + 1)) return true;
		}
		return false;
	}
	void solve() {
		if (dfs(1)) for (int i = 1; i <= n; ++ i) cout << a[i] << ' ';
		else cout << "cut_the_watermelon_with_a_hand\n";
		return;
	}
}

namespace sub2 {
	void solve() {
		int l = 1;
		while (l <= n and b[l] == 2) l ++;
		for (int i = 1; i <= n; ++ i)
			cout << (i == l ? 1 : 2) << ' ';
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> b[i];
	if (n <= 10) return sub1::solve(), 0;
	else return sub2::solve(), 0;
	return 0;
}
