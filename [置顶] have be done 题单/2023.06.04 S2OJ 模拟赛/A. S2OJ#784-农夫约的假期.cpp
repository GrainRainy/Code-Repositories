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

const int N = 1e3 + 10;
int n, m, z;
LL graph[N][N];
LL mn = 0x3f3f3f3f, mx, my;
// baoli 
struct per { int x, y; } q[N];
LL avrx, avry, ans = 0;

int main() {
	input(n), input(m), input(z);
	if (n <= 1000) {
		int x, y, q;
		for (int i = 1; i <= m; ++ i) {
			input(x), input(y), input(q);
			for (int j = 1; j <= n; ++ j)
				for (int k = 1; k <= n; ++ k)
					graph[j][k] += getD(x, y, j, k) * z + q; 
		} 
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				if (graph[i][j] < mn) {
					mn = graph[i][j];
					mx = i, my = j;
				}
		output(mn), output(mx, ' '), output(my);
		return 0;
	}
	for (int i = 1, tmp; i <= m; ++ i) {
		input(q[i].x), input(q[i].y), input(tmp);
		ans += tmp;
		avrx += q[i].x, avry += q[i].y;
	} 
	avrx /= m, avry /= m;
	for (int i = 1; i <= m; ++ i)
		ans += getD(avrx, avry, q[i].x, q[i].y) * z;
	output(ans), output(avrx, ' '), output(avry);
	return 0;
}
