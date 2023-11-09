#include <bits/stdc++.h>
using namespace std;
const int L = 1e7 + 10;
bool st[L];
vector<int> stk;

bool jg(int x) {
	for (; x; x /= 10)
		if (x % 10 == 7) return true;
	return false;
}

void solve() {
	int x; cin >> x;
	auto itl = lower_bound(stk.begin(), stk.end(), x);
	if (*itl != x) cout << "-1\n";
	else cout << *(++itl) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	stk.emplace_back(1);
	for (int i = 2; i <= (int)1e7 + 5; ++ i) {
		if (!st[i]) {
			if (jg(i)) for (int j = 2; j * i <= (int)1e7 + 5; ++ j)
				st[j * i] = true;
			else stk.emplace_back(i);
		}
	}
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
