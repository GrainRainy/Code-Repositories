#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
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
using LL = long long;

const int N = 1e5 + 10;
const LL INF = 1e18 + 7;
LL n, q, k[N], b[N];
LL x, tmp, ans;
LL mx1, mx2, mn1, mn2, mxi, mni;

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(k[i]), input(b[i]);
	input(q);
	while (q --) {
		input(x);
		mx1 = mx2 = ans = -INF, mn1 = mn2 = INF;
		for (int i = 1; i <= n; ++ i) {
			if (k[i] * x + b[i] > mx1) { 
				mx2 = mx1;
				mx1 = k[i] * x + b[i], mxi = i;
			} else if (k[i] * x + b[i] > mx2) mx2 = k[i] * x + b[i];
			if (k[i] * x + b[i] < mn1) {
				mn2 = mn1;
				mn1 = k[i] * x + b[i], mni = i;
			} else if (k[i] * x + b[i] < mn2) mn2 = k[i] * x + b[i];
		}
		for (int i = 1; i <= n; ++ i) {
			if (k[i] < 0) {
				if (mni != i) ans = max(ans, k[i] * mn1 + b[i]);
				else ans = max(ans, k[i] * mn2 + b[i]);
			} else {
				if (mxi != i) ans = max(ans, k[i] * mx1 + b[i]);
				else ans = max(ans, k[i] * mx2 + b[i]);
			}
		}
		output(ans);
	}
	return 0;
}
