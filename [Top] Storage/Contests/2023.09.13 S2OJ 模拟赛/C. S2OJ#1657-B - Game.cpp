#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
int n, v[N], top, f;
LL tot[2], ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

int main() {
	rd(n);
	for (int i = 1, x; i <= n; ++ i) {
		rd(x);
		if (x >= 0) ans += x, f = 1;
		else v[++ top] = x;
	}
	sort(v + 1, v + top + 1, greater<int>());
	if (!f) {
		ans += v[1];
		for (int i = 2; i <= top; ++ i) tot[i & 1] += v[i];
		cout << ans + max(tot[0], tot[1]) << '\n';
	} else {
		for (int i = 1; i <= top; ++ i) tot[i & 1] += v[i];
		cout << ans + tot[!(top & 1)] << '\n';
	}
	return 0;
}
