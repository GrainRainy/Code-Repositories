#include <bits/stdc++.h>
using namespace std;

char s[10] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};

void solve()
{
	getchar();
	char c;
	c = getchar();
	for (int i = 0; i <= 9; i ++)
		if (c == s[i])
		{
			puts("YES");
			return;
		}
	puts("NO");
	return;
}

int main()
{
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
