#include <bits/stdc++.h>

using namespace std;

void div(int x)
{
	if (x == 0) cout << 0;
	if (x == 1)
	{
		cout << "2(0)";
		return;
	}
	if (x == 2)
	{
		cout << 2;
		return;
	}
	
	for (int i = 14; i >= 0; i --)
	{
		if (pow(2, i) <= x)
		{
			x -= pow(2, i);
			if (i == 1 && x != 0)
			{
				cout << "2+";
				continue;
			}
			else if (i == 1 && x == 0)
			{
				cout << 2;
				break;
			}
			cout << "2(";
			div(i);
			cout << ")";
			if (x != 0) cout << "+";
		}
		
	}
		
}

int main()
{
	int n;
	cin >> n;
	
	div(n);
		
	return 0;
}
