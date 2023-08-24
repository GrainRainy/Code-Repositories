#include <iostream>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}
using namespace IO;
int t, n, m;

void solve() {
	input(n), input(m);
	if (n == 1 or m == 1) return puts("Yes"), void();
	if (n <= m) return puts("No"), void();
	for (int i = 2; i <= n / i; ++ i)
		if (!(n % i) and i <= m) return puts("No"), void();
	return puts("Yes"), void();
}

int main() {
	input(t); while (t --) solve();
	return 0;
}
