#include <iostream>
#include <cstring>
#include <algorithm>

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

const int N = 20;
const int INF = 0x3f3f3f3f;
int n, m;
int a[N][N], b[N][N];
int f[1 << N];

int dp(int s, bool p) {
	if (~f[s]) return f[s];
	f[s] = p ? -INF : INF;
	int x = n, y = 0;
	for (int i = 0; i < n + m - 1; ++ i) {
		(s >> i & 1) ? x -- : y ++;
		if ((s >> i & 3) != 1) continue;
		if (p) f[s] = max(f[s], dp(s ^ (3 << i), p ^ 1) + a[x][y]);
		else f[s] = min(f[s], dp(s ^ (3 << i), p ^ 1) - b[x][y]);
	}
	return f[s];
}

int main() {
	input(n), input(m);
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			input(a[i][j]);
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			input(b[i][j]);
	memset(f, 0xff, sizeof f);
	f[((1 << n) - 1) << m] = 0;
	return output(dp((1 << n) - 1, 1)), 0;
}
