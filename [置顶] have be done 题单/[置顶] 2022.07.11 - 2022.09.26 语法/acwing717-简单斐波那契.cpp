#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a = 0;
	int b = 1;
	int c;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i ++)
	{
		cout << a << " ";
		c = a + b;
		a = b;
		b = c;
	}
	return 0;
}
