#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10; 
int n, m, pos, nxt[N];
char s[N], p[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s + 1 >> p + 1, n = strlen(s + 1), m = strlen(p + 1);
	for (int i = 2; i <= m; ++ i) {
		while (pos and p[i] != p[pos + 1]) pos = nxt[pos];
		if (p[i] == p[pos + 1]) pos ++;
		nxt[i] = pos;
	}
	pos = 0;
	for (int i = 1; i <= n; ++ i) {
		while (pos and s[i] != p[pos + 1]) pos = nxt[pos];
		if (s[i] == p[pos + 1]) pos ++;
		if (pos == m) cout << i - m + 1 << '\n';
	}
	for (int i = 1; i <= m; ++ i) cout << nxt[i] << ' ';
	return cout << '\n', 0;
}
