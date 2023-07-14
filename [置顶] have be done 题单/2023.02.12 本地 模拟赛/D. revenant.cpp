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

const int N = 210;
int n, t;
int nums[N];
// basic things

int main()
{
	freopen("revenant.in","r",stdin);
	freopen("revenant.out","w",stdout);
	input(n);
	int idx = 0;
	for (int i = 1; i <= n; i ++)
	{
		input(nums[++ idx]);
		while (nums[idx] == nums[idx - 1]) nums[-- idx] ++;
	}
	cout << idx << endl;
}

