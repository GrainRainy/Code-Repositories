#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, c[N], to[N], q, x, ans;
int clr[N], ctp;
bool jg2 = true, jg3 = true, st[N];

namespace sub4 {
	bool jg = true;
	int pre[N], ans[N];	
	void solve() {
		for (int i = 1; i <= n; ++ i) {
			ans[i] = pre[c[i]] ? i - pre[c[i]] + 1 : i + 1;
			pre[c[i]] = i;
		}
		while (q --) cin >> x, cout << ans[x] << '\n';
		return;
	}
}

namespace sub5 {
	bool jg = true;
	int pre[N], suf[N], ans[N];
	void solve() {
		for (int i = n; i; -- i) if (!suf[c[i]]) suf[c[i]] = i;
		for (int i = 1; i <= n; ++ i) {
			ans[i] = n - suf[c[i]] + i + 1;
			if (pre[c[i]]) ans[i] = i - pre[c[i]] + 1;
			if (i != 1) ans[i] = min(ans[i - 1] + 1, ans[i]);
			pre[c[i]] = i;
		}
		ans[1] = min(ans[n] + 1, ans[1]);
		for (int i = 2; i <= n; ++ i) ans[i] = min(ans[i], ans[i - 1] + 1);
		ans[1] = min(ans[n] + 1, ans[1]);
		for (int i = 2; i <= n; ++ i) ans[i] = min(ans[i], ans[i - 1] + 1);
		ans[1] = min(ans[n] + 1, ans[1]);
		for (int i = 2; i <= n; ++ i) ans[i] = min(ans[i], ans[i - 1] + 1);
		while (q --) cin >> x, cout << ans[x] << '\n';
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> c[i], jg2 &= c[i] == 1;
	for (int i = 1; i <= n; ++ i) {
		cin >> to[i], jg3 &= to[i] == 1;
		sub4::jg &= (i == 1) ? (to[i] == 1) : (to[i] == i - 1);
		sub5::jg &= (i == 1) ? (to[i] == n) : (to[i] == i - 1);
	}
	cin >> q;
	if (sub4::jg) return sub4::solve(), 0;
	if (sub5::jg) return sub5::solve(), 0;
	while (q --) {
		cin >> x;
		if (jg2) cout << "2\n";
		else if (jg3) cout << (c[x] == c[1] ? "2\n" : "3\n");
		else {
			ans = 0;
			while (!st[c[x]]) {
				ans ++;
				st[c[x]] = true, clr[++ ctp] = c[x];
				x = to[x];
			}
			cout << ans + 1 << '\n';
			while (ctp) st[clr[ctp --]] = false;
		}
	}
	return 0;
}
