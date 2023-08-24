#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	getline (cin ,a);
	for (char &c : a)
	{
		if ((c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'))
		{
			if (c == 'z') c = 'a';
			else if (c == 'Z') c = 'A';
			else c += 1;
		}
	}
	
	cout << a;
	return 0;
}
