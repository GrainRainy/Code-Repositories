#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
using LL = long long;

template <typename T>
inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; c < '0' or c > '9'; c = getchar())
		f |= (c == '-');
	for (; c >= '0' and c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + (c ^ '0');
	x = f ? -x : x;
}

template <typename T>
inline void output(T x, char ed = ' ')
{
	static short st[64], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

void solve()
{
	LL g; input(g);
	LL h; input(h);
	
	LL tmp = h;
	while (tmp <= g) tmp *= h;
	
	LL a = g * ceil(1.0 * tmp / g);
	LL b = h * a + g;
	output(a), output(b), puts("");
}

int main()
{
	LL t; input(t);
	while (t --) solve();
	return 0;
}
