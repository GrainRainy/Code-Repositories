#include <bits/stdc++.h>
using namespace std;
long long n, pre, nw, ca, cb;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	rd(n), rd(pre);
	for (int i = 1; i < n; ++ i) {
		rd(nw);
		if (nw > pre) ca += nw - pre;
		else cb += pre - nw;
		pre = nw;
	}
	return printf("%lld\n%lld\n", max(ca, cb), abs(ca - cb) + 1), 0;
}
