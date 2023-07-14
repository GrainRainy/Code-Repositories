#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
using namespace std;
template <typename T>
inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
inline void output(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], idx;
	do st[idx ++] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

typedef pair<double, double> PDD;

const int N = 15;
const int S = 1 << N;
const int INF = 1e8;
int n;
PDD dots[N + 10];
// basic things
double f[N + 10][S];
// refers to the cost of staying at i and state is j 

double dist(PDD x, PDD y)
{
	double xa = x.first, ya = x.second;
	double xb = y.first, yb = y.second;
	double ans = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
	return ans;
}

signed main()
{
	input(n);
	for (int i = 1; i <= n; i ++)
		cin >> dots[i].first >> dots[i].second;
	// input
	for (int i = 0; i <= N; i ++)
		for (int j = 0; j < (1 << N); j ++)
			f[i][j] = INF;
	for (int i = 1; i <= n; i ++)
		f[i][1 << (i - 1)] = dist(dots[i], dots[0]);
	// init
	for (int j = 1; j < (1 << n); j ++)
		for (int i = 1; i <= n; i ++)
			if ((j >> (i - 1)) & 1)
				for (int k = 1; k <= n; k ++) // Ã¶¾Ù×ªÒÆ 
				{
					if (((j >> (k - 1)) & 1) && k != i)
						f[i][j] = min(f[i][j], f[k][j - (1 << (i - 1))] + dist(dots[i], dots[k]));
				}
	// dp
	
	double ans = INF;
	for (int i = 1; i <= n; i ++)
		ans = min(ans, f[i][(1 << n) - 1]);
	printf("%.2lf\n", ans);
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j < (1 << n); j ++)
			cerr << f[i][j] << " ";
		cerr << endl;
	}
	return 0;
}

