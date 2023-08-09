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

using IO::input;
using namespace std;
int n, a, b, cnt, mn = 0x3f3f3f3f;
long long sum;

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) {
		input(a), input(b);
		a < b ? swap(a, b), 1 : cnt ++;
		sum += a;
		mn = min(mn, a - b);
	}
	return printf("%lld\n", (cnt & 1 ? sum - mn : sum)), 0;
}
