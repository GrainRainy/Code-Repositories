#include <bits/stdc++.h>
using namespace std;
int main ()
{
	string a,suba;
	while (cin >> a >> suba)
	{
		int p = 0;
		for (int i = 1;i < a.size(); i ++)
		{
			if (a[i] > a[p]) p = i;
		}
		cout << a.substr (0, p + 1) << suba << a.substr (p + 1) << endl;
	}
	return 0;
} 
