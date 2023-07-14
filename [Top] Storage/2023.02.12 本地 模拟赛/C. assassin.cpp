#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template <typename T>
void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
void output(T x, char ed = '\n') // '\n' or ' ', remember to check
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++ tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp --] | '0');
	putchar(ed);
}

int n, t;

int main()
{
//	freopen("assassin.in","r",stdin);
//	freopen("assassin.out","w",stdout);
	input(n), input(t);
	int tmpa, tmpb;
	for (int i = 1; i < n; i ++)
		input(tmpa), input(tmpb);
	for (int i = 1; i <= t; i ++)
	{
		int a, b, c, d;
		input(a), input(b), input(c), input(d);
		if (a == c || a == d)
		{
			puts("YES");
			continue;
		}
		if (b == c || b == d)
		{
			puts("YES");
			continue;
		}
		puts("NO");
	}
	return 0;
		
}

