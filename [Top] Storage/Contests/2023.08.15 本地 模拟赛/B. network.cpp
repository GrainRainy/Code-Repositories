#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, cnt, ans;
struct P {
	int a, b, id;
}ps[N];
int path[N];
bool st[N];

namespace sub1 {
	bool judge = true;
	bool cmp(const P &a, const P &b) {
		return a.a < b.a;
	}
	void solve() {
		sort(ps + 1, ps + n + 1, cmp);
		for (int i = 1; i <= n; ++ i) {
			if (st[i]) continue;
			while (cnt < ps[i].a) ans ++, st[n --] = true, cnt ++;
			st[i] = true, cnt ++;
		}
		cout << ans << '\n';
		return;
	}
}

void dfs(int pos) {
	if (pos == n + 1) {
		cnt = 0;
		int res = 0;
		for (int i = 1; i <= n; ++ i) {
			if (cnt < ps[path[i]].a) res += ps[path[i]].b;
			cnt ++;
		}
		ans = min(ans, res);
	}
	for (int i = 1; i <= n; ++ i) {
		if (st[i]) continue;
		st[i] = true, path[pos] = i;
		dfs(pos + 1);
		st[i] = false, path[pos] = 0;
	}
}

int main() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1, a, b; i <= n; ++ i) {
		cin >> a >> b;
		ps[i] = {a, b, i};
		sub1::judge &= (b == 1);
	}
	if (sub1::judge) return sub1::solve(), 0;
	ans = 0x3f3f3f3f;
	dfs(1);
	cout << ans << endl;
	return 0;
}
