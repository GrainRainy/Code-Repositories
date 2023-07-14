#include <bits/stdc++.h>
template <typename T>
void input(T &x)
{
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
void output(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++ tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp --] | '0');
	putchar(ed);
}
using namespace std;

const int N = 5e4 + 10;

int n, m;
int room[N]; // 差分，卡卡常也许能过（？）
int op, x, y;
// 理论复杂度 O(nm) 2,500,000,000 祈祷数据水点 ~  
int now, len;

int main()
{
	input(n), input(m);
	while (m --)
	{
		input(op);
		if (!(op ^ 1))
		{
			input(x);
			len = 0;
			for (int i = 1; i <= n; ++ i)
			{
				now += room[i];
				if (now) len = 0;
				if (!now) ++ len;
				if (len == x)
				{
					output(i - len + 1);
					++ room[i - len + 1];
					-- room[i + 1];
					break;
				}
			}
			if (len ^ x) puts("0");
		}
		else
		{
			input(x), input(y);
			-- room[x];
			++ room[x + y];
		}
	}
	return 0;
}
