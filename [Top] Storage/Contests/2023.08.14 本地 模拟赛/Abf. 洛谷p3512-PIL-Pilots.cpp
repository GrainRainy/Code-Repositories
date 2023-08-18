#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for(; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using IO::input;
using namespace std;
const int N = 3e6 + 10;
int t, n, a[N], ans;
int main() {
	freopen("a.in", "r", stdin);
	input(t), input(n);
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	for (int len = 1; len <= n; ++ len) {
		for (int l = 1; l + len - 1 <= n; ++ l) {
			int mn = 2147483600, mx = -1;
			for (int i = l; i <= l + len - 1; ++ i) 
				mn = min(mn, a[i]), mx = max(mx, a[i]);
			if (mx - mn <= t) ans = len;
		}
	}
	cout << ans << endl;
	return 0;
}
