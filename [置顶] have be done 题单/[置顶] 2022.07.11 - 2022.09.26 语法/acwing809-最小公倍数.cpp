#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b)
{
	for (int i = (a > b) ? a : b; i > 0; i ++)
		if (!(i % a) && !(i % b)) return i;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << lcm(a, b);
	return 0;
}
