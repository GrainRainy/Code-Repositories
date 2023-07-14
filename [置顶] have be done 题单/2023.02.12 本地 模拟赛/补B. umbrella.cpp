#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
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

ULL mul(ULL a, ULL b)
{
	return a * b % MOD;
}

int qm(int x, int y = MOD - 2)
{
	int tmp = 1;
	while(y)
	{
		if(y & 1) tmp = mul(tmp,x);
		x = mul(x, x);
		y >>= 1;
	}
	return tmp;
}

int jie[N], inv[N];
int C(int n, int m)
{
	if(n < m) return 0;
	return mul(jie[n], mul(inv[m], inv[n-m]));
}

int main()
{
	freopen("umbrella.in","r",stdin);
	freopen("umbrella.out","w",stdout);
	// ¼ÇµÃÉ¾×¢ÊÍ£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
	input(n), input(m);
	// input and special judge
	jie[0] = 1;
	for(int i = 1; i <= m; i ++)
		jie[i] = mul(jie[i - 1], i);
	
	inv[m] = qm(jie[m]);
	for(int i = m - 1; i >= 0; i --)
		inv[i]=mul(inv[i+1],i+1);
	// init
	cout << 1ll * C(m - 1, n - 1) * qm(2, n - 1) % MOD << endl;
}

