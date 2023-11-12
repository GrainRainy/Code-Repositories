#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e3 + 10;
const int MOD = 998244353;
int q, n, k;

namespace sub1 {
	const int M = 4e6 + 10;
	LL p[N], stk[M], stp;
	bool st[N];
	void dfs(int pos) {
		if (pos == n + 1) {
			stp ++;
			for (int i = 1; i <= n; ++ i)
				stk[stp] += p[i] * i * (n - i + 1);
			return;
		}
		for (int i = 1; i <= n; ++ i)
			if (!st[i]) {
				st[i] = true, p[pos] = 1 + log2(i & -i);
				dfs(pos + 1);
				st[i] = false, p[pos] = 0;
			}
	}
	
	void sol() {
		memset(st, 0, sizeof n);
		memset(stk, 0, sizeof stk), stp = 0;
		dfs(1);
		sort(stk + 1, stk + stp + 1);
		cout << stk[k] % MOD << '\n';
	}
}

namespace sub2 {
	LL w[N], c[N], ans, ans2;
	void sol() {
		ans = 0, ans2 = 0x3f3f3f3f3f3f3f3f;
		for (int i = 1; i <= n; ++ i)
			w[i] = 1 + log2(i & -i), c[i] = i * (n - i + 1);
		sort(w + 1, w + n + 1), sort(c + 1, c + n + 1, greater<LL>());
		for (int i = 1; i <= n; ++ i) ans += w[i] * c[i];
		if (k == 1) return cout << ans % MOD << '\n', void();
		for (int i = 1; i <= n; ++ i)
			for (int j = i + 1; j <= n; ++ j)
				ans2 = min(ans2, ans + (w[j] - w[i]) * c[i] + (w[i] - w[j]) * c[j]);
		cout << ans2 % MOD << '\n';
	}
}

int main() {
	freopen("npc.in", "r", stdin);
	freopen("npc.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> q;
	while (q --) {
		cin >> n >> k;
		if (n <= 10) sub1::sol();
		else sub2::sol();
	}
	return 0;
}
