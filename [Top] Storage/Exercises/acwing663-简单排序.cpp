#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int maxab = (a > b) ? a : b;
	int max3 = (maxab > c) ? maxab : c;
	int minab = (a < b) ? a : b;
	int min3 = (minab < c) ? minab : c;
	cout << min3 << endl;
	cout << a + b + c - min3 - max3 << endl;
	cout << max3 << endl;
	cout << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	return 0;
}
