#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	if (b.size() > a.size())
		swap(a, b);
		// a is the longest
	for  (int i = 0; i < a.size(); i ++)
	{
		a = a.substr(1) + a[0];
		for (int j = 0; j <= a.size() - b.size(); j ++)
			if (a.substr(j, b.size()) == b)
			{
				cout << "true" << endl;
				return 0;
			}
	}
	cout << "false" << endl;
	return 0;
}
