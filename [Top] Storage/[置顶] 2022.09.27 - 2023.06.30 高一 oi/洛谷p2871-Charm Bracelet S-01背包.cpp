#include <iostream>
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

const int N = 4e3;
const int M = 1.3e4;
int n, m, w[N], d[N], f[M];

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) {
		input(w[i]), input(d[i]);
		for (int j = m; j >= w[i]; -- j) f[j] = max(f[j], f[j - w[i]] + d[i]);
	}
	printf("%d\n", f[m]);
}
