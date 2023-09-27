#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int n, m, sa[N], x[N], y[N], c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s + 1;
	n = strlen(s + 1), m = 122;
	for (int i = 1; i <= n; ++ i) c[x[i] = s[i]] ++;
	for (int i = 1; i <= m; ++ i) c[i] += c[i - 1];
	for (int i = n; i; -- i) sa[c[x[i]] --] = i;
	for (int k = 1, top; k <= n; k <<= 1) {
		top = 0;
		for (int i = n - k + 1; i <= n; ++ i) y[++ top] = i;
		for (int i = 1; i <= n; ++ i) if (sa[i] > k) y[++ top] = sa[i] - k;
		for (int i = 1; i <= m; ++ i) c[i] = 0;
		for (int i = 1; i <= n; ++ i) c[x[i]] ++;
		for (int i = 1; i <= m; ++ i) c[i] += c[i - 1];
		for (int i = n; i; -- i) sa[c[x[y[i]]] --] = y[i];
		swap(x, y);
		x[sa[1]] = 1, top = 1;
		for (int i = 2; i <= n; ++ i) 
			x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] and y[sa[i] + k] == y[sa[i - 1] + k]) ? top : ++ top;
		if (top == n) break;
		m = top;
	}
	for (int i = 1; i <= n; ++ i) cout << sa[i] << ' ';
	return cout << '\n', 0;
}
