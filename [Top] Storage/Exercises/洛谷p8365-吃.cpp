#include <iostream>
#include <cstring>
#include <algorithm>
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

int n;
const int N = 5e5 + 10;
const int MOD = 1e9 + 7;
int mul[N], add[N];
LL res = 1;
double smax;
int smax_idx = -1;

int main()
{
	input(n);
	for (int i = 0; i < n; i ++)
		input(mul[i]);
	for (int i = 0; i < n; i ++)
	{
		input(add[i]);
		if (mul[i] == 1) res = res + add[i];
	}
	
	smax = res;
	for (int i = 0; i < n; i ++)
	{
		if (mul[i] == 1) continue;
		if ((res + add[i]) * 1.0 / mul[i] > smax)
		{
			smax = (res + add[i]) * 1.0 / mul[i];
			smax_idx = i;
		}
	}
		
	
	res %= MOD;
	if (smax_idx != -1) res = (res + add[smax_idx]) % MOD;
	for (int i = 0; i < n; i ++)
	{
		if (mul[i] == 1) continue;
		if (i != smax_idx) res = res * mul[i] % MOD;
	}
	cout << res << endl;
	return 0;
}

/*
5
1 2 3 4 5
100 200 300 400 500
*/
