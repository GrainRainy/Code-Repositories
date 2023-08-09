#include <bits/stdc++.h>
#define getD(a, b, c, d) (LL)abs(a - c) + (LL)abs(b - d)

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) 
			f |= (c == '-');
		for (; isdigit(c); c = getchar())
			x = x * 10 + (c ^ '0');
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
using LL = long long;

const int N = 1e5 + 10;
int n, m, z, x[N], y[N];
int ansx, ansy;
LL ansv;

int main() {
	input(n), input(m), input(z);
	for (int i = 1, tmp; i <= m; ++ i) {
		input(x[i]), input(y[i]), input(tmp);
		ansv += tmp;
	}
	sort(x + 1, x + m + 1), sort(y + 1, y + m + 1);
	ansx = x[m / 2 + m % 2], ansy = y[m / 2 + m % 2];
	for (int i = 1; i <= m; ++ i)
		ansv += getD(ansx, ansy, x[i], y[i]) * z; 
	output(ansv), output(ansx, ' '), output(ansy);
	return 0;
}
