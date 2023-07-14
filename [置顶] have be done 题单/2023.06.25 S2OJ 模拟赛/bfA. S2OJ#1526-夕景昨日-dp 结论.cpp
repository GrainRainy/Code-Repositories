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
using LL = long long;

const int N = 1e5 + 10;
const int M = 5e5 + 10;
LL n, a[N], mx, f[M];

void solve() {
	memset(f, 0, sizeof f);
	input(n);
	for (int i = 1; i <= n; ++ i) input(a[i]), mx = max(mx, a[i]);
	if (n > 1000) return puts("Yes"), void();
	for (int i = 1; i <= n; ++ i) {
		for (int j = mx; j > a[i]; -- j) 
			f[j] += f[j - a[i]];
		f[a[i]] ++;
	}

	for (int i = 1; i <= n; ++ i)
		if (f[a[i]] > 1) return puts("Yes"), void();
	return puts("No"), void();
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
