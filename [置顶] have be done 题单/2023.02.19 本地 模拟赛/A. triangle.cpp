#include <bits/stdc++.h>
#include <winbase.h>
using namespace std;
int n;
string s[3][10];
void output(int n, int l)
{
	if (n <= 2 && l <= 4) 
		cout << s[n][l];
	else if (l <= (1 << (n - 1)))
	{
			for (int i = 1; i <= (1 << (n + 1)) / 4; i ++)
				printf(" ");
			output(n - 1, l);
			for (int i = 1; i <= (1 << (N + 1)) / 4; i ++)
				printf(" ");
	}
	else
	{
		output(n - 1, l - (1 << (n - 1)));
		output(n - 1, l - (1 << (n - 1)));
	}
	return;
}

int main()
{
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	s[1][1] = " /\\ ";
	s[1][2] = "/__\\";
	s[2][1] = "   /\\   ";
	s[2][2] = "  /__\\  ";
	s[2][3] = " /\\  /\\ ";
	s[2][4] = "/__\\/__\\";
	cin >> n;
	for (int i = 1; i <= pow(2, n); i ++)
	{
		output(n, i);
		puts("");
	}
	return 0;
}
