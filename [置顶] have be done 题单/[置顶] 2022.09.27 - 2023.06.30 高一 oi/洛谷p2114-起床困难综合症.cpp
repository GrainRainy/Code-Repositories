#include <bits/stdc++.h>
#define enter putchar('\n')

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar(); bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T, typename... Args> void input(T &x, Args&... args) {
	input(x), input(args...);
}
template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 30; // LOGN 
string a;
int n, m, tmp;
int _1 = 0x7fffffff, _0 = 0, ans;

int main() {
	input(n), input(m);
	while (n --) {
		cin >> a; input(tmp);
		if (a[0] == 'A') _1 &= tmp, _0 &= tmp;
		if (a[0] == 'O') _1 |= tmp, _0 |= tmp;
		if (a[0] == 'X') _1 ^= tmp, _0 ^= tmp;
	}
	for (int i = N; i >= 0; -- i) {
		if (_0 & (1 << i)) ans |= (1 << i);
		else if (m > (1 << i) and _1 & (1 << i))
			m -= (1 << i), ans |= (1 << i);
	}
	output(ans);
	return 0;
}
