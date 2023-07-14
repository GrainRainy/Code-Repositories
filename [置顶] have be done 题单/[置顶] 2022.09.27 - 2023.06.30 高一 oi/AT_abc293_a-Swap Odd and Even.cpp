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

template <typename T> inline void output(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[64], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed); 
}

int n;
string a;

inline void swp(int i)
{
	if (2 * i - 1 == 2 * i) return;
	char c = a[2 * i - 1];
	a[2 * i - 1] = a[2 * i];
	a[2 * i] = c;
}

int main()
{
	cin >> a; 
	n = a.size();
	a = '$' + a;
	for (int i = 1; i <= n / 2; i ++)
		swp(i);
	cout << a.substr(1) << endl;
	return 0;
}
