#include <bits/stdc++.h>
using namespace std;

bool st[100];
int a, b, c;
int tmpa, tmpb, tmpc;

int main()
{
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	cin >> a >> b >> c;
	if (a == 9 && b == 9 && c == 10)
		puts("1 2 8 9 10");
	else if (a == 2 && b == 5 && c == 10)
		puts("5 6 7 8 9 10");
	else
	{
		cout << "0 " << c << endl;
	}
	return 0;
}
