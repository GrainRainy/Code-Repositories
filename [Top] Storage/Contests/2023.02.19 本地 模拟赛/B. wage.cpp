#include <bits/stdc++.h>
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
template <typename T>
inline void output(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], idx = 0;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
int n, m;
int prc[N];

int main()
{
	freopen("wage.in", "r", stdin);
	freopen("wage.out", "w", stdout);
	input(n), input(m);
	for (int i = 1; i <= n; i ++)
	{
		int tmp; input(tmp);
		prc[1] += tmp;
		sort(prc + 1, prc + m + 1);
	}
	cout << prc[m] << endl;
	return 0;
}
