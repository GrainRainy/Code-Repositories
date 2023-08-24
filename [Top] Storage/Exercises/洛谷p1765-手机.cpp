#include <bits/stdc++.h>
using namespace std;

int press(char c)
{
	if (c == 'a' || c == 'd' || c == 'g' || c == 'j' || c == 'm' || c == 'p' || c == 't' || c == 'w' || c == ' ')
		return 1;
	else if (c == 'b' || c == 'e' || c == 'h' || c == 'k' || c == 'n' || c == 'q' || c == 'u' || c == 'x')
		return 2;
	else if (c == 'z' || c == 's')
		return 4;
	else if (c == 'c' || c == 'f' || c == 'i' || c == 'l' || c == 'o' || c == 'r' || c == 'v' || c == 'y')
		return 3;
	else return 0;
}

int main()
{
	string s;
	getline(cin, s);
	int sum = 0;
	for (int i = 0; i < s.size(); i ++)
		sum += press(s[i]);
		
	cout << sum <<endl;
	return 0; 
}
