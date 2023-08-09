#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cctype>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n')
{
	static short st[64], top = 0;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
const int K = 30;
int n, q;
int to_idx[N], back_idx[N];
int father[N][K + 10];

inline void init()
{
	for (int k = 1; k <= K; k ++)
		for (LL i = 1; i <= n and i + (LL)(1 << k) - 1 <= 1e9; i ++)
			father[i][k] = father[father[i][k - 1]][k - 1];
}

inline int query(int now, int s)
{
	for (int k = K; k >= 0; k --)
	{
		if ((1 << k) <= s)
		{
			now = father[now][k];
			s -= (1 << k);
		}
	}
	return now;
}

int main()
{
	input(n), input(q);
	for (int i = 1; i <= n; i ++)
	{
		int u, d;
		input(u), input(d);
		to_idx[u] = i, back_idx[i] = u;
		father[u][0] = d;
	}
	
	init();
	
	for (int i = 1; i <= q; i ++)
	{
		int k, s;
		input(k), input(s);
		output(to_idx[query(back_idx[k], s)]);
	}
	return 0;
}

