#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s, s1, s2;
	char n;
	while (cin >> n, n != ',') s += n;
	while (cin >> n, n != ',') s1 += n; 
	while (cin >> n) s2 += n;
	
	bool flag1 = 0, flag2 = 0;
	int bg1, ed1, bg2, ed2;
	for (int i = 0; i + s1.size() <= s.size(); i ++)
	{
		if (s.substr(i, s1.size()) == s1)
		{
			flag1 = 1;
			bg1 = i;
			ed1 = i + s1.size() - 1;
			break;
		}
	}
	for (int i = s.size() - 1; i - s2.size() >= 0; i --)
	{
		if (s.substr(i - s2.size() + 1, s2.size()) == s2)
		{
			flag2 = 1;
			bg2 = i - s2.size() + 1;
			ed2 = i;
			break;
		}
	}
	if (!flag1 || !flag2 || ed1 >= bg2)
		cout << "-1" << endl;
	else
		cout << bg2 - ed1 - 1<< endl;
	return 0;
}
