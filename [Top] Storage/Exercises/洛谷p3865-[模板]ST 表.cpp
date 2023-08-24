#include <iostream>
#include <cctype>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
void print(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++ tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
const int J = 17;

int n, m;
int nums[N], f[N][J], log[N];

void init()
{
	for (int j = 0; j < J; j ++)
		for (int i = 1; i + (1 << j) - 1 <= n; i ++)
			if (!j) f[i][j] = nums[i];
			else f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
	// st init
	log[1] = 0;
    for(int i = 2; i < N; i ++)
        log[i] = log[i >> 1] + 1;
}

void query(int l, int r)
{
	int len = r - l  + 1;
	int k = log[len];
	print(max(f[l][k], f[r - (1 << k) + 1][k]));
}

int main()
{
	read(n), read(m);
	for (int i = 1; i <= n; i ++)
		read(nums[i]);
	
	init();
	
	while (m --)
	{
		int l, r;
		read(l), read(r);
		query(l, r);
	}
	
	return 0;
}
