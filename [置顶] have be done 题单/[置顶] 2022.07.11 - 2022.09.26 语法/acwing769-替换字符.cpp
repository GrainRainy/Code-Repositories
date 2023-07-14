#include <bits/stdc++.h>
using namespace std;

char s[40];

int main()
{
	cin >> s;
	char a;
	cin >> a;
	for (int i = 0; s[i]; i ++)
		if (s[i] == a) s[i] = '#';
	
	puts(s);
	return 0;
}
