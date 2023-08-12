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
const int N = 40;
LL n, m, c[N], w[N], ans;

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) input(c[i]);
	for (int i = 1; i <= n; ++ i) input(w[i]);
	if (n <= 21) {
		for (LL s = 1, totc, totw; s < (1 << n); ++ s) {
			totc = totw = 0;
			for (int i = 1; i <= n; ++ i) 
				if ((s >> (i - 1)) & 1) totc ^= c[i], totw += w[i];
			if (totc <= m) ans = max(ans, totw);
		}
	} else for (int i = 1; i <= n; ++ i) ans += w[i];
	cout << max(ans, (LL)0) << endl;
	return 0;
}
