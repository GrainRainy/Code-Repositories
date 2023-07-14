#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

template <typename T>
inline void output(T x, char ed = ' ')
{
	static short st[30], idx;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

const int N = 1e6 + 10;
int n, p[N];
char s[N];
bool st[N];

inline void manacher()
{
	s[0] = '$', s[n + 1] = '^';
	
	for (int i = 1, mid = 0, mr = 0; i <= n; ++ i)
	{
		p[i] = 0;
		if (i < mr) p[i] = min(mr - i, p[(mid << 1) - i]);
		while (s[i + p[i] + 1] == s[i - p[i] - 1]) p[i] ++;
		if (i + p[i] > mr) mr = i + p[i], mid = i;
	}
}

void solve()
{
	memset(p, 0, sizeof p);
	
	cin >> s + 1;
	n = strlen(s + 1);
	
	manacher();
	
	for (register int i = n; i > 0; -- i)
	{
		st[i] = false;
		if (i + p[i] == n) st[i] = true;
		else if (st[i + p[i]] and i - p[i] == 1) st[i] = true;
	}
	for (register int i = 1; i <= n; ++ i)
		if (st[i]) output(i);
	puts("");
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
