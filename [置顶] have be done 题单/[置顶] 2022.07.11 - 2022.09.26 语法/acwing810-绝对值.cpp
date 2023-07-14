#include <bits/stdc++.h>
using namespace std;

int abs(int n)
{
	if (n < 0) return -n;
	else return n;
}

int main()
{
	int n;
	cin >> n;
	cout << abs(n);
	return 0;
}
