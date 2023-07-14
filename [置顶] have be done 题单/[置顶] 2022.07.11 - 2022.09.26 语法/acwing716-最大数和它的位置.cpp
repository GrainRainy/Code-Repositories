#include <bits/stdc++.h>
using namespace std;
int main()
{
	int max = 0;
	int n;
	int num;
	for (int i = 1;i <= 100;i ++)
	{
		cin >> n;
		if (n > max)
		{
			max = n;
			num = i;
		}
	}
	
	cout << max << endl;
	cout << num << endl;
	return 0;
}
