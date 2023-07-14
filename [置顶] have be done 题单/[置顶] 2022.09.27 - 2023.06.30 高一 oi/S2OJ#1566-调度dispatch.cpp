#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

template <typename T>
inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e6 + 10;
int a[N], b[N], c[N], d[N];

void solve()
{
	int n, m;
	input(n), input(m);
	for (int i = 1; i <= n; i ++)
		input(a[i]), c[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; i ++)
		input(b[i]), d[i] = b[i] - b[i - 1];
	for (int i = 1; i + m - 1 <= n; i ++)
		c[i + m] -= d[i] - c[i],  c[i] += d[i] - c[i];
	for (int i = 1; i <= n; i ++)
		if (c[i] != d[i])
		{
			puts("N0");
			return;
		}
	puts("YES");
	return;
}

int main()
{
	int t;
	input(t);
	while (t --) solve();
	return 0;
}
