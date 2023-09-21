#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, nxt[N];
string nw, ans;

int mxlen(string s) {
	s = "0" + s;
	int pos = 0;
	for (int i = 2; i < s.size(); ++ i) {
		while (pos and s[i] != s[pos + 1]) pos = nxt[pos];
		if (s[i] == s[pos + 1]) pos ++; 
		nxt[i] = pos;
	}
	return nxt[s.size() - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1, pos; i <= n; ++ i) {
		cin >> nw;
		pos = mxlen(nw + "#$%^" + ans.substr(ans.size() - min(ans.size(), nw.size())));
		for (int j = pos; j < nw.size(); ++ j) ans += nw[j];
	}
	cout << ans << '\n';
	return 0;
}
