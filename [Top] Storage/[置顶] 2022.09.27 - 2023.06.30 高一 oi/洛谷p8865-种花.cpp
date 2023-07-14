#include <iostream>
#include <cstring>
#include <algorithm>

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

const int N = 1e3 + 10;
const int MOD = 998244353;
int n, m, C, F;
LL ansc, ansf;
int f[N][N];
bool gph[N][N]; 
int cntc, cntf;
int jis, jil, jilf;

void solve()
{
	ansc = ansf = 0;
	memset(f, 0, sizeof f); // 多测不清空，保龄两行泪 
	input(n), input(m), input(C), input(F);
	
	char sc;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			do sc = getchar(); while (sc < 48 || sc > 57);
			gph[i][j] = sc - '0';
		}
	}	
	// input
	for (int i = 1; i <= n; i ++)
		for (int j = m - 1; j > 0; j --)
			if (gph[i][j]) f[i][j] = -1;
			else if (!gph[i][j + 1])f[i][j] = f[i][j + 1] + 1;
	// init
	
	for (int j = 1; j < m; j ++)
	{
		cntc = cntf = 0;
		for (int i = 1; i <= n; i ++)
		{
			if (f[i][j] == -1)
			{
				cntc = cntf = 0;
				continue;
			}
			ansc = ansc % MOD + (1ll * f[i][j] * (cntc % MOD)) % MOD;
			ansf = (ansf % MOD + cntf % MOD) % MOD;
			cntf = (cntf + (1ll* f[i][j] * cntc % MOD)) % MOD;
			cntc = (cntc +  max(0,f[i-1][j])) % MOD;
		}
	}
	cout << C * ansc << " " << F * ansf << endl;	
	return;
}

int main()
{
	int t; input(t);
	int id; input(id);
	while (t --) solve();
	return 0;	
}

