#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define LY(p) freopen (p".in", "r", stdin); freopen (p".out", "w", stdout)
#define LL long long
#define dbl double
#define lf long double
#ifdef WIN32
#define L_L "%I64d"
#else
#define L_L "%lld"
#endif
#define N 210
int n, t[N], d[N], st[N], sd[N];
LL f[N][N];

int main()
{
	LY("product20");
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d %d", &t[i], &d[i]);
		st[i] = st[i - 1] + t[i];
		sd[i] = sd[i - 1] + d[i];
	}

	memset (f, 0x3f, sizeof (f));
	for (int i = 1; i <= n; i++)
		f[i][i] = d[i] * t[i], f[i][i - 1] = 0;
	f[n + 1][n] = 0;

	for (int l = 1; l < n; l++)
		for (int i = 1; i + l <= n; i++) {
			int j = i + l;
			for (int k = i; k <= j; k++)
				f[i][j] = min (f[i][k - 1] + f[k + 1][j] + 1LL * (st[k - 1] - st[i - 1]) * (sd[j] - sd[k]) + 1LL * (st[j] - st[i - 1]) * d[k],
							   f[i][j]);
		}

	printf (L_L, f[1][n]);
	return 0;
}
