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
		static short st[40], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
int n, m;
multiset<int> st;

int main() {
	input(n), input(m);
	st.insert(0), st.insert(n);
	for (int i = 1, x, l, r; i <= m; ++ i) {
		input(x);
		l = *(--st.lower_bound(x)), r = *st.upper_bound(x);
		output((LL)(x - l) * (r - x));
		st.insert(x);
	}
	return 0;
}
