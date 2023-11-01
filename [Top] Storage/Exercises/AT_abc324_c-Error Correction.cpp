#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, stk[N], top;
string t, s;

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	cin >> n >> t;
	for (int i = 1, dt; i <= n; ++ i) {
		cin >> s;
		if (abs((int)s.size() - (int)t.size()) > 1) continue;
		if (s.size() == t.size()) {
			dt = 0;
			for (int i = 0; i < t.size(); ++ i) {
				dt += t[i] != s[i];
				if (dt > 1) break;
			}
			if (dt <= 1) stk[++ top] = i;
		} else if (s.size() - 1 == t.size()) {
			dt = 0;
			for (int i = 0; i < s.size(); ++ i) {
				dt += s[i] != t[i - dt];
				if (dt > 1) break; 
			}
			if (dt <= 1) stk[++ top] = i;
		} else {
			dt = 0;
			for (int i = 0; i < t.size(); ++ i) {
				dt += s[i - dt] != t[i];
				if (dt > 1) break; 
			}
			if (dt <= 1) stk[++ top] = i;
		}
	}
	cout << top << '\n';
	for (int i = 1; i <= top; ++ i) cout << stk[i] << ' ';
	return cout << '\n', 0;
}
