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
using LL = long long;
const int N = 1e7 + 10;
int n, a[N], stk[N], top;
LL ansa, ansb;
struct CartesianTree {
	int l, r;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
}tree[N];

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) {
		input(a[i]);
		while (top and a[stk[top]] > a[i]) l(i) = stk[top --];
		if (top) r(stk[top]) = i;
		stk[++ top] = i;
	}
	for (int i = 1; i <= n; ++ i) {
		ansa ^= (LL)i * (l(i) + 1);
		ansb ^= (LL)i * (r(i) + 1);
	}
	return printf("%lld %lld\n", ansa, ansb), 0;
}
