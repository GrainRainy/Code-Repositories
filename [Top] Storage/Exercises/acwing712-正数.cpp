#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sum = 0;
	double n;
	for (int i = 1;i <= 6;i++)
	{
		cin >> n;
		if (n > 0) sum++;
	}
	cout << sum << " positive numbers" << endl;
	return 0;
}
