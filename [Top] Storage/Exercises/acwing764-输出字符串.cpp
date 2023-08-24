#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a, b;
	getline (cin, a);
	b = a;
	for (int i = 0; i < a.size() - 1; i ++)
	{
		b[i] = a[i] + a[i + 1];
	}
	b[a.size() - 1] =(char)(a[0] + a[a.size() - 1]);
	cout << b << endl;
	return 0;
}
