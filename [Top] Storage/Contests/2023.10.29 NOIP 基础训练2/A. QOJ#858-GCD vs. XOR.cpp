#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
int t, n, mx;
LL ans, c[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int main() {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	int t; rd(t);
	while (t --) {
		rd(n), mx = 0, ans = 0;
		for (int i = 1, a; i <= n; ++ i) rd(a), mx = max(mx, a), c[a] ++;
		for (int i = 1; i <= mx; ++ i) {
			for (LL j = 1; (LL)(j + 1) * i <= mx; ++ j)
				if ((j * i ^ (j + 1) * i) == i) {
//					cout << j * i << ' ' << (j + 1) * i << '\n';
					ans += c[j * i] * c[(j + 1) * i];
				}
		}
		ot(ans);
		for (int i = 1; i <= mx; ++ i) c[i] = 0;
	}
	return 0;
}
