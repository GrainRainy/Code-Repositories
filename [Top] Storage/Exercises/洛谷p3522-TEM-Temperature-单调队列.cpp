#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, ans = 1, l[N], r[N], q[N], hd = 1, tl;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

int main() {
	rd(n);
	for (int i = 1, pre; i <= n; ++ i) {
		rd(l[i]), rd(r[i]), pre = i;
		while (hd <= tl and r[i] < l[q[hd]]) hd ++;
		if (hd <= tl) ans = max(ans, i - q[hd] + 1);
		while (hd <= tl and l[q[tl]] < l[i]) pre = q[tl --];
		l[pre] = l[i], q[++ tl] = pre;
	}
	return cout << ans << '\n', 0;
} 
