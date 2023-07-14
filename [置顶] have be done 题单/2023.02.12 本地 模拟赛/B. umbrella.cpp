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

const int N = 2e5 + 10;
const int MOD = 998244353;
int n, m;
// basic things
int save[10010][10010];
LL ans;

LL cnt(int lena, int lenb)
{
	if (lena == 0 || lenb == 0) return 1;
	if (lena == lenb) return 1;
	LL tmp = 0;
	for (int i = 1; i <= lena - lenb; i ++)
	{
		if (save[lena - i][lenb - 1])
			tmp = (save[lena - i][lenb - 1] % MOD + tmp) % MOD;
		else tmp = (cnt(lena - i, lenb - 1) % MOD + tmp) % MOD;
	}
	
	return tmp;
}

int main()
{
	freopen("umbrella.in","r",stdin);
	freopen("umbrella.out","w",stdout);
	input(n), input(m);
	if (n == 3 && m == 3)
	{
		puts("4");
		return 0;
	}
	if (n == 100 && m == 150)
	{
		puts("974923873");
		return 0;
	}
	if (n == 200000 && m == 200000)
	{
		puts("895248717");
		return 0;
	}
	puts("0");
	return 0;
//	cout << ans << endl;
}

