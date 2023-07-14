#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int a;
	cin >> a;
	while (cin >> n,n <= 0);
	
	int sum = 0;
	for (int i = 0;i < n;i ++)
	{
		sum += i + a;
	}
	cout << sum << endl;
	return 0;
}
