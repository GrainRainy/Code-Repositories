#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a, b;
	getline (cin, a);
	for (int i = 0; i < a.size(); i ++)
	{
		b += a[i] + a[(i + 1) % a.size()];
	}
	cout << b << endl;
	return 0;
}
