#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	b = ' ' + b + ' ';
	for (int i = 0; i < a.size(); i ++)
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 32;
	for (int i = 0; i < b.size(); i ++)
		if (b[i] >= 'A' && b[i] <= 'Z')
			b[i] += 32;
	//cin and change
	int dir, cnt = 0;
	bool flag = 1;
	for (int i = 1 ;i <= b.size() - a.size(); i ++)
	{
		if (a[0] == b[i])
		{
			if (b[i - 1] == ' ' && b[i + a.size()] == ' ')
			{
				if (b.substr(i, a.size()) == a)
				{
					cnt ++;
					if (flag)
					{
						dir = i;
						flag = 0;
					}
				}
			}
			
		}
	}
	
	if (cnt == 0)
		cout << -1 << endl;
	else
		cout << cnt << " " << dir - 1<< endl;
	return 0;	
}
