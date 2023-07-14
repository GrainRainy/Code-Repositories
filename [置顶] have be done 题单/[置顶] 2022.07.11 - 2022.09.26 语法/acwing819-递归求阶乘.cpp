#include <bits/stdc++.h>
using namespace std;

int jiecheng(int a)
{
	if (a == 1) return 1;
	return a * jiecheng(a - 1);
}

int main()
{
	int n;
	cin >> n;
	cout << jiecheng(n) << endl;
	return 0;
}
