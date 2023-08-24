#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	cin >> x;
	int cnt = 0;
	for (int i = x;cnt < 6;i ++)
	{
		if (i % 2)
		{
			cout << i << endl;
			cnt ++;
		}
	}
	return 0;
}
