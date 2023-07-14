#include <iostream>
#define min(a, b) (((a) < (b)) ? (a) : (b))
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

const int N = 1e7 + 10;
LL n, x, y, f[N];

int main() {
	input(n), input(x), input(y);
	for (int i = 1; i <= n; ++ i) {
		if (i & 1) f[i] = min(f[i - 1] + x, f[i / 2 + 1] + x + y);
		else f[i] = min(f[i - 1] + x, f[i / 2] + y);
	}
	cout << f[n] << endl;
	return 0;
}
