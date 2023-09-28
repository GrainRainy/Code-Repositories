#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
char s[N << 1];
int n, m, c[N << 1], x[N << 1], y[N << 1];
int sa[N << 1], rk[N << 1];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		do s[i] = getchar(); while (s[i] < 'A' or s[i] > 'Z');
		s[(n << 1) - i + 2] = s[i];
	}
	s[n + 1] = 'A' - 1, n = (n << 1) + 1, m = 90;
	for (int i = 1; i <= n; ++ i) c[x[i] = s[i]] ++;
	for (int i = 2; i <= m; ++ i) c[i] += c[i - 1];
	for (int i = n; i; -- i) sa[c[x[i]] --] = i;
	for (int k = 1, top; k <= n; k <<= 1) {
		top = 0;
		for (int i = n - k + 1; i <= n; ++ i) y[++ top] = i;
		for (int i = 1; i <= n; ++ i) if (sa[i] > k) y[++ top] = sa[i] - k;
		memset(c, 0, sizeof(int) * (m + 10));
		for (int i = 1; i <= n; ++ i) c[x[i]] ++;
		for (int i = 2; i <= m; ++ i) c[i] += c[i - 1];
		for (int i = n; i; -- i) sa[c[x[y[i]]] --] = y[i];
		swap(x, y);
		x[sa[1]] = 1, top = 1;
		for (int i = 2; i <= n; ++ i)
			x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] and y[sa[i] + k] == y[sa[i - 1] + k]) ? top : ++ top;
		if (top == n) break;
		m = top;
	}
	for (int i = 1; i <= n; ++ i) rk[sa[i]] = i;
	int l = 1, r = n >> 1, cnt = 0;
	while (l <= r) {
		putchar(s[rk[l] < rk[n - r + 1] ? l ++ : r --]);
		if (++ cnt == 80) cnt = 0, putchar('\n');
	}
	return 0;
}
