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

template <typename T> inline void output(T x, char ed = ' ')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[64], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed); 
}

const int N = 2e5 + 10;
int n, cnt;
int nums[N]; // index to value
bool st[N];

int main()
{
	input(n);
	for (int i = 1; i <= n; i ++)
		input(nums[i]);
	// input
	for (int i = 1; i <= n; i ++)
		if (!st[i]) st[nums[i]] = true;
	
	for (int i = 1; i <= n; i ++)
		if (!st[i]) cnt ++;
	output(cnt); puts("");
	for (int i = 1; i <= n; i ++)
		if (!st[i]) output(i);
	puts("");
	return 0;
}
