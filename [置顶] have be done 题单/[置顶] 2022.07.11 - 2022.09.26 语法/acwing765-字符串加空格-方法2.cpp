#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	getline(cin, a);
	
	for (auto c : a)
		b = b + c + ' ';
	
	cout << b << endl;
	return 0;
}
