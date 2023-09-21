#include <bits/stdc++.h>
template <typename T>
void input(T &x)
{
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
void output(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++ tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp --] | '0');
	putchar(ed);
}
/*
 *  or ' ', remember to check
 */
using namespace std;
const int N = 2e5 + 10;


void solve()
{
	string a; int n;
	input(n); cin >> a;
	
	int back[26] = {0}, front[26] = {0};
	
	for (auto s : a) back[s - 'a'] ++;
	
	int ans = 0;
	for (int i = 0; i < n - 1; i ++)
	{
		front[a[i] - 'a'] ++;
		back[a[i] - 'a'] --;
		
		int tmp = 0;
		for (int i = 0; i < 26; i ++)
			tmp += (front[i] > 0) + (back[i] > 0);
		
		ans = max(ans, tmp);
	}
	
	output(ans);
	return;
}

int main()
{
	int t;
	input(t);
	while (t --) solve();
	return 0;
}
