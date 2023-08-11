#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 100 + 10;
int n, t[N], d[N];
int cnt[N], pre[N];
LL ans = 0x3f3f3f3f3f3f3f3f;
int stk[N], top, ary[N], at;

void dfs(int pos) {
	if (pos == n) {
		at = 0;
		cnt[n] = n - pre[n - 1];
		for (int i = 1; i <= n; ++ i) {
			stk[++ top] = i;
			for (int j = 1; j <= cnt[i]; ++ j)
				ary[++ at] = stk[top], top --;
		}
		LL tmp = 0, s = 0;
		for (int i = 1; i <= n; ++ i) {
			s += t[ary[i]];
			tmp += s * d[ary[i]];
		}
		ans = min(ans, tmp);
		return;
	}
	for (int i = 0; i + pre[pos - 1] <= pos; ++ i) {
		cnt[pos] = i;
		pre[pos] = pre[pos - 1] + cnt[pos];
		dfs(pos + 1);
	}
}

int main() {
//	freopen("guard.in", "r", stdin);
//	freopen("guard.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> t[i] >> d[i];
	dfs(1);
	cout << ans << endl;
	return 0;
}
