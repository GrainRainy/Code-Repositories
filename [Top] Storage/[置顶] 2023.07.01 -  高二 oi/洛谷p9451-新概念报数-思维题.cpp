#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
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
using LL = long long;
const int N = 5e4 + 10;
LL n, tmp;

inline int count(LL u) {
	int res = 0;
	while (u) res ++, u -= lowbit(u);
	return res;
}

int main() {
	int t; input(t);
	while (t --) {
		input(n);
		tmp = count(n);
		if (tmp >= 3) puts("No,Commander");
		else if (tmp <= 1) output(n + 1);
		else output(n + lowbit(n));
	}
	return 0;
}
