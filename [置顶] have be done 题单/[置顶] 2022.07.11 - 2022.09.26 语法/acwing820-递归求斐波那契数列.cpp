#include <bits/stdc++.h>
using namespace std;

int feibonaqi(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 1;
	return feibonaqi(n - 1) + feibonaqi(n - 2);
}

int main()
{
	int n;
	cin >> n;
	cout << feibonaqi(n) << endl;
	return 0;
}
