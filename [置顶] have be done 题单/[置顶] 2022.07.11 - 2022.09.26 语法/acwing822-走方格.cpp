#include <bits/stdc++.h>
using namespace std;

int cnt;
int n, m;

void f(int a, int b)
{
	if (a == n && b == m) cnt ++;
	else
	{
		if (a < n) f(a + 1, b);
		if (b < m) f(a, b + 1);
	}
}

int main()
{
	cin >> n >> m;
	f(0, 0);
	cout << cnt << endl;
	return 0;
}
