#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	cin >> k;
	bool flag = 0;
	for (int i = 10000; i <= 30000; i ++)
	{
		int sub1 = i / 100;
		int sub2 = i / 10 % 1000;
		int sub3 = i % 1000;
		if (!(sub1 % k) && !(sub2 % k) && !(sub3 % k))
		{
			cout << i << endl;
			flag = 1;
		}
	}
	if (!flag) cout << "No" << endl;
	return 0;
}
