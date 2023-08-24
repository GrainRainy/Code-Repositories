#include <bits/stdc++.h>
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
using namespace std;
const int N = 2e4 + 10;
int n, a[N], ans, sum;

int main() {
	input(n), input(a[1]);
	if (n == 1) return printf("%d\n", a[1]);
	for (int i = 2; i <= n; ++ i) {
		input(a[i]);
		ans = max(ans, a[i] + a[i - 1]);
		sum += a[i];
	}
	ans = max({ans, a[1] + a[n], (int)ceil(1.0 * (sum + a[1]) / (n >> 1))});
	return printf("%d\n", ans), 0;
}
