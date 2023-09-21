#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, nxt[N];
char s[N];
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> s + 1;
	for (int i = 2, j = 0; i <= n; ++ i) {
		while (j and s[i] != s[j + 1]) j = nxt[j];
		if (s[i] == s[j + 1]) j ++;
		nxt[i] = j;
	}
	for (int i = 1, j; i <= n; ++ i) {
		j = nxt[i];
		while (nxt[j]) j = nxt[j];
		if (nxt[i]) nxt[i] = j;
		if (j and j << 1 <= n) ans += i - j;
	}
	return cout << ans << '\n', 0;
}
