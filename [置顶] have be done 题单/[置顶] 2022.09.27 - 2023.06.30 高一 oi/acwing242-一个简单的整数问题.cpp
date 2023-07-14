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
/*
 *  or ' ', remember to check
 */
using namespace std;

const int N = 1e5 + 10;

int n, m;
int nums[N << 1];

int lowbit(int x)
{
	return x & -x;
}

void change(int pos, int val)
{
	for (int i = pos; i <= n; i += lowbit(i))
		nums[i] += val;
}

int query(int l)
{
	int sum = 0;
	for (int i = l; i > 0; i -= lowbit(i))
		sum += nums[i];
	return sum;
}

int main()
{
	input(n), input (m);
	for (int i = 1; i <= n; i ++)
	{
		int x;
		input(x);
		change(i, x), change(i + 1, -x);
	}
	while (m --)
	{
		char c; int l, r, d;
		cin >> c;
		if (c == 'C')
		{
			input(l), input(r), input(d);
			change(l, d);
			change(r + 1, -d);
		}
		else
		{
			input(l);
			output(query(l));
		}
	}
	return 0;
}
