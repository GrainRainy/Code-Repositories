#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;
using ULL = unsigned long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x; 
}

const int LOGN = 63;
ULL p[LOGN + 10], ans, n, tmp;

inline void insert(ULL x) {
	for (int i = LOGN; ~i; i --) {
		if (!(x >> i)) continue;
		if (!p[i]) { p[i] = x; break; }
		x ^= p[i];
	}
}

int main() {
	input(n);
	for (int i = 1; i <= n; i ++) {
		input(tmp); insert(tmp);
	}
	for (int i = LOGN; ~i; i --) {
		ans = max(ans, ans ^ p[i]);
	}
	return cout << ans << '\n', 0;
}
