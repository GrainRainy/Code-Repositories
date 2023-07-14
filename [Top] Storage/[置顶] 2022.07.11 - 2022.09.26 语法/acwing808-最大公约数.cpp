#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	for (int i = (a > b) ? a : b; i; i --)
	{
		if (!(a % i) && b % i == 0)
			return i;
	}
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	return 0;
}
