#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 3e5 + 10;
int n, nxt[N], c[N];
char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s + 1, n = strlen(s + 1);
	for (int i = 1, pre; i <= 1; ++ i) {
//	for (int i = 1, pre; i <= n; ++ i) {
		pre = i;
		for (int j = 2, p = 0; j <= n; ++ j) {
			while (p  and s[j] != s[p + 1]) p = nxt[p];
			if (s[j] == s[p + 1]) p ++;
			nxt[j] = p;
			if (p == i) debug(j)
			if (p == i and p - pre + 1 >= i) c[j] ++;
			else if (p == i) break;
		}
	}
	for (int i = 1; i <= n; ++ i) cout << c[i] << '\n';
	return 0;
}
