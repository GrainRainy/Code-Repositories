#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	getline (cin, s);
	s.pop_back();
	stringstream ssin(s);
	string b;
	int len = 0;
	string save;
	while (ssin >> b)
	{
		if (b.size() > len)
		{
			len = b.size();
			save = b;
		}
	}
	cout << save << endl;
	return 0;
}
