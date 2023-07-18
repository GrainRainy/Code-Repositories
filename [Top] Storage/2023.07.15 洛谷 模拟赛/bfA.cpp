#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
const int N = 1e5 + 10;
int n, m;
bool st[N];

int main() {
	input(n), input(m);
	st[0] = st[n] = true;
	for (int i = 1, x, l, r; i <= m; ++ i) {
		input(x);
		l = r = x;
		while (!st[l]) l --; while (!st[r]) r ++;
		output((x - l) * (r - x));
		st[x] = true;
	}
}
