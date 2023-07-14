#include <bits/stdc++.h>
using namespace std;
bool dfs(int round, int cnt2, int cnt1, bool isa) { // return 1 if A win
	if (!(round % 3)) cnt2 ++;
	if (!cnt2 and !cnt1) return !isa;
	if (isa) {
		bool f = false;
		if (cnt2) f |= dfs(round + 1, cnt2 - 1, cnt1 + 1, 0);
		if (cnt2) f |= dfs(round + 1, cnt2 - 1, cnt1, 0);
		if (cnt1) f |= dfs(round + 1, cnt2, cnt1 - 1, 0);
		return f;
	} else {
		bool f = true;
		if (cnt2) f &= dfs(round + 1, cnt2 - 1, cnt1 + 1, 1);
		if (cnt2) f &= dfs(round + 1, cnt2 - 1, cnt1, 1);
		if (cnt1) f &= dfs(round + 1, cnt2, cnt1 - 1, 1);
		return f;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t, n; cin >> t;
	while (t --) {
		cin >> n;
//		bool f = dfs(1, n, 0, 1);
		if (!((n - 1) % 3)) cout << "Acestar" << '\n';
		else cout << "Blueqwq" << '\n';
	}
	return 0;
}
