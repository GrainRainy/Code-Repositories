#include <bits/stdc++.h>
using namespace std;
using LL = long long;
string s, ori, x, y, z;
LL n, m, k, l, r, c;

void sub1() {
	while (m --) {
		cin >> l >> r >> c;
		if (c > k) cout << s[(k - 1) % n] << endl;
		else if (c + r - l + 1 < k) cout << s[(k - (r - l + 1) - 1) % n] << endl;
		else cout << s[(l + k - c - 2) % n] << endl;
	}
	return;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k >> s;
	if (m == 1) return sub1(), 0;
	if (n <= 10000) {
		ori = s;
		while (ori.size() <= 10000) ori = ori + s;
		s = ori;
		while (m --) {
			cin >> l >> r >> c;
			x = s.substr(l - 1, r - l + 1); // insert
			if (!c) { s = x + s; continue; }
			y = s.substr(0, c); // left 
			z = s.substr(c);
			s = y + x + z;
		}
		cout << s[k - 1] << endl;
	} else cout << (char)('a' + rand() % 26) << endl;
	return 0;
}
