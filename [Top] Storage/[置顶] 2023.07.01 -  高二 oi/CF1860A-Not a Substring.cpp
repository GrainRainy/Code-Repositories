#include <bits/stdc++.h>
using namespace std;
string s;
void solve() {
	int mx = -1e9, pre = 0;
	cin >> s;
	if (s == "()") return cout << "No\n", void();
	cout << "Yes\n";
	int x = s.find(")(");
	if (x >= 0 and x < s.size()) {
		for (int i = 1; i <= s.size(); ++ i) cout << '(';
		for (int i = 1; i <= s.size(); ++ i) cout << ')';
	} else {
		for (int i = 1; i <= s.size(); ++ i) cout << "()";
	} 
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
