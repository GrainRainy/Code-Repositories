#include <bits/stdc++.h>
using namespace std;

int fangan(int n)
{
	if (n == 1 ) return 1;
	else if (n == 2) return 2;
	return fangan(n - 1) + fangan(n - 2);
}

int main()
{
	int n;
	cin >> n;
	cout << fangan(n) << endl;
	return 0;
}
