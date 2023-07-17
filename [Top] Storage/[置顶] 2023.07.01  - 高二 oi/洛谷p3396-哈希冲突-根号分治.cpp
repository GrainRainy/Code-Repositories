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
const int N = 1.5e5 + 10;
const int SN = 4e2;
int n, m, siz;
char op[3];
int val[N], ans[SN][SN];

void init() {
	for (int p = 1; p <= siz; ++ p)
		for (int i = 1; i <= n; ++ i)
			ans[p][i % p] += val[i];
}

void modify(int pos, int value) {
	for (int p = 1; p <= siz; ++ p)
		ans[p][pos % p] += value - val[pos];
	val[pos] = value;
}

int main() {
	input(n), input(m);
	siz = sqrt(n);
	for (int i = 1; i <= n; ++ i) input(val[i]);
	init();
	for (int i = 1, x, y, res; i <= m; ++ i) {
		cin >> op;
		input(x), input(y);
		if (*op == 'A') {
			if (x <= siz) output(ans[x][y]);
			else {
				res = 0;
				for (int i = y; i <= n; i += x) res += val[i];
				output(res);
			}
		} else modify(x, y);
	}
	return 0;
}
