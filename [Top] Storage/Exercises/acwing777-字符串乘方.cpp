#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	while(cin >> a, a[0] != '.')
	{
		int cnt = 0;
		if (a[0] == 0)
		{
			cout << cnt << endl;
			break;
		}
		for (int i = 1; i <= a.size(); i ++) //lenth
		{
			for (int j = 0; j + i <= a.size(); j += i) //position
			{
				if(a.substr(j, i) != a.substr(0, i)) break;
				else cnt ++;
			}
			if (cnt == a.size() / i)
			{
				cout << cnt << endl;
				break;
			}
			else cnt = 0;
		}
	}
	return 0;
}
