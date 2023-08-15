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
const int N = 1e5 + 10;
int n, k, a[N];
LL pre[N], res = 0x3f3f3f3f3f3f3f3f;

LL sm(int l, int r) {
	int mid = l + r >> 1;
	if ((r - l + 1) & 1) return pre[r] - pre[mid] - pre[mid - 1] + pre[l - 1];
	return pre[r] - (pre[mid] << 1) + pre[l - 1];
}

int main() {
	input(n), input(k);
	for (int i = 1; i <= n; ++ i) input(a[i]);
	for (int i = 1, b; i <= n; ++ i) {
		input(b);
		pre[i] = a[i] - b;
	}
	sort(pre + 1, pre + n + 1);
	for (int i = 1; i <= n; ++ i) pre[i] += pre[i - 1];
	for (int l = 1; l + n - k - 1 <= n; ++ l) 
		res = min(res, sm(l, l + n - k - 1));
	return printf("%lld\n", res), 0;
}
