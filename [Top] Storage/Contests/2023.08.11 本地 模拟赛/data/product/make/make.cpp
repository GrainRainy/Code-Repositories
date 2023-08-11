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
int _n[] = {15, 100, 200};
int _t[] = {100, 1000, 1000};
int _d[] = {100, 1000, 1000};
int n = 200, t = 10000, d = 10000;

int main()
{
	srand ((unsigned) time (NULL));
	int T = 15;
	freopen ("product20.in", "w", stdout);
	if (T <= 6)
		T = 0;
	else if (T <= 10)
		T = 1;
	else
		T = 2;
	n = _n[T], t = _t[T], d = _d[T];
	
	printf ("%d\n", n);
	for (int i = 1; i <= n; i++) 
		printf ("%d %d\n", rand() % t + 1, rand() % d + 1);
	return 0;
}
