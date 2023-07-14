#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '0');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;

const int N = 2e3 + 10;
int n, a[N], l, r;

void solve() {
	input(n);
	for (int i = 1; i <= n; ++ i) {
		input(a[i]);
		if (a[i] == n) l = r = i;
	}
	if (r == 1) for (int i = 2; i <= n; ++ i) 
		if (a[i] == n - 1) l = r = i;
	if (r != n) r --, l --;
	while (a[l - 1] > a[1]) l --;
	for (int i = r + 1; i <= n; ++ i) output(a[i], ' ');
	for (int i = r; i >= l; -- i) output(a[i], ' ');
	for (int i = 1; i < l; ++ i) output(a[i], ' ');
	return puts(""), void();
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
