#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
	template <typename T, typename ...Args>
	inline void rd(T &x, Args&... args) { rd(x), rd(args...); }
}
using IO::rd;
using namespace std;
const int M = 3e4 + 10;
int n, t1, t2, t3, f[M], up, dn, tmp, ans = 0x3f3f3f3f;

int main() {
	rd(n);
	memset(f, 0x3f, sizeof f); f[0] = 0;
	for (int i = 1; i <= n; ++ i) {
		rd(t1, t2, t3); up += max(t1, t3);
		for (int j = up; j >= dn; -- j) {
			tmp = 0x3f3f3f3f;
			if (t1 and j >= t1) tmp = min(tmp, f[j - t1]);
			if (t2) tmp = min(tmp, f[j] + t2);
			if (t3 and j >= t3) tmp = min(f[j - t3] + t3, tmp);
			f[j] = tmp;
			while (f[dn] == 0x3f3f3f3f) dn ++;
		}
	}
	for (int i = dn; i <= up; ++ i) ans = min(ans, max(i, f[i]));
	return cout << ans << '\n', 0;
}
