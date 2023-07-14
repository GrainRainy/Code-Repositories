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
		static short st[40], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
LL n, ans[N]; LL z;
struct Psn {
	LL c, w, id;
	bool operator < (const Psn &t) const {
		if ((w - c) * (t.w - t.c) < 0) return w - c > 0;
		if (w - c < 0) return w > t.w;
		return c < t.c;
	}
}a[N];

int main() {
	input(n), input(z);
	for (int i = 1; i <= n; ++ i)
		input(a[i].c), input(a[i].w), a[i].id = i;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) {
		z -= a[i].c;
		if (z <= 0) return puts("NIE"), 0;
		z += a[i].w;
		ans[i] = a[i].id;
	}
	puts("TAK");
	for (int i = 1; i <= n; ++ i) output(ans[i], " \n"[i == n]);
	return 0;
}
