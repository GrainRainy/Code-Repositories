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

using namespace std;
using namespace IO;
using LL = long long;

const int N = 1e5 + 10;
LL n, k, pos[N];
LL ans = 0x3f3f3f3f3f3f3f3f;

int main() {
	input(n), input(k);
	for (int i = 1; i <= n; ++ i) input(pos[i]);
	
	for (int tmpl = 1, tmpr = k; tmpr <= n; ++ tmpl, ++ tmpr) 
		ans = min(ans, pos[tmpr] - pos[tmpl] + min(abs(pos[tmpl]), abs(pos[tmpr])));
	cout << ans << endl;
	return 0;
}
