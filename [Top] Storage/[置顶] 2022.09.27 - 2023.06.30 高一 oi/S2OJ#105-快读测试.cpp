#include <cstdio>
using LL = long long;
template <typename T>
inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; c < '0' or c > '9'; c = getchar())
		f |= c == '-';
	for (; c >= '0' and c <= '9'; c = getchar())
		x = x * 10 + (c ^ '0');
	x = f ? -x : x;
}
template <typename T>
inline void output(T x, char ed = '\n') // '\n' or ' ', remember to check
{
	if (x < 0) putchar('-'), x = -x;
	static short st[100], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const LL N = 3e6;
LL ans;
LL n;

int main()
{
	input(ans);
    for (int i = 1; i < N; ++ i)
    {
    	input(n);
    	ans ^= n;
	}
    output(ans);
}
