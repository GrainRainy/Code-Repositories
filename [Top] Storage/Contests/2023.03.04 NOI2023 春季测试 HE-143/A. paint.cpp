#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; c < '0' or c > '9'; c = getchar())
		f |= (c == '-');
	for (; c >= '0' and c <= '9'; c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = ' ')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], top = 0;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
int n, m, q;
int idxl[N], vall[N];
int idxh[N], valh[N];
// idx and value 
// start from 1 

inline void solve()
{
	memset(idxl, 0, sizeof idxl);
	memset(vall, 0, sizeof vall);
	memset(idxh, 0, sizeof idxh);
	memset(valh, 0, sizeof valh);
	// init
	
	input(n), input(m), input(q);
	for (int i = 1; i <= q; i ++)
	{
		int op, x, c;
		input(op), input(x), input(c);
		
		if (op == 0) idxh[x] = i, valh[x] = c;
		else if (op == 1) idxl[x] = i, vall[x] = c;
	}
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			if (idxl[j] > idxh[i]) output(vall[j]);
			else if (idxl[j] < idxh[i]) output(valh[i]);
			else output(0);
		}
		puts("");
	}
	return;	
}

int main()
{
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	// file stream
	
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
