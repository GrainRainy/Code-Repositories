#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e4 + 10;
const int L = 1 << 10;
int n, q, a[N], nxt[N][L];
LL b[N], sm, ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) rd(a[i]);
	for (int i = 1; i <= n; ++ i) rd(b[i]);
	for (int j = 1; j < L; ++ j) nxt[n + 1][j] = n + 1;
	for (int i = n; i; -- i) 
		for (int j = 1; j < L; ++ j)
			nxt[i][j] = (a[i] | j) == j ? i : nxt[i + 1][j];
	rd(q);
	for (int i = 1, l, r, x; i <= q; ++ i) {
		rd(l), rd(r), rd(x), sm = 0;
		while (x and nxt[l][x] <= r) l = nxt[l][x], x -= a[l], sm += b[l];
		ans ^= sm;
	}
	return cout << ans << '\n', 0;
}
