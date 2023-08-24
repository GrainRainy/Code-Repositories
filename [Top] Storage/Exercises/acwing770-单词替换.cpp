# include <bits/stdc++.h> 
using namespace std;
int main()
{
	string a ,b ,c;
	getline (cin, a);
	cin >> b >> c;
	
	stringstream ssin(a);
	string d;
	while (ssin >> d)
	{
		if (d == b) d = c;
		cout << d << " ";
	}
	return 0;
}
