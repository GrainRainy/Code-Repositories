#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;
int n, c[N], ps[N], f[N] = {1};

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) rd(c[i]);
	for (int i = 1; i <= n; ++ i) {
		f[i] = f[i - 1];
		if (c[i] != c[i - 1]) upd(f[i], ps[c[i]]), upd(ps[c[i]], f[i - 1]);
	}
	return cout << f[n] << '\n', 0;
}
