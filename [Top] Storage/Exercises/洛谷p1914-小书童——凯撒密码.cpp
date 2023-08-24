#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	int n;
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i ++)
		for (int j = 0; j < n; j ++)
		{
			if (s[i] == 'z')  s[i] = 'a';
			else s[i] ++;
		}
	cout << s << endl;
	return 0;
}
