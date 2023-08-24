#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

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
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 3e6 + 10;

int n, p;
int inv[N];

int main(){
	input(n), input(p);
	
	inv[1] = 1;
	for (int i = 2; i <= n; i ++) {
		output(inv[i - 1]);
		inv[i] = (LL)(p - p / i) * inv[p % i] % p;
	}
	return output(inv[n]), 0;
}
