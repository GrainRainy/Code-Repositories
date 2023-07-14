#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	getline (cin, a);
	getline (cin, b);
	
	for (char &c : a)
		if (c >= 'A' && c <= 'Z') c = c + 32;
	for (char &d : b)
		if (d >= 'A' && d <= 'Z') d = d + 32;
	
	if (a == b) cout << "=";
	else if (a < b) cout << "<";
	else cout << ">";
	return 0;
}
