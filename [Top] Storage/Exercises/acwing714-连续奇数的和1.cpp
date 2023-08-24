#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y;
	cin >> x >> y;
	int sum = 0;
	int a = max(x,y);
	int b = min(x,y);
	for (int i = b + 1;i < a;i++)
	{
		if ((i % 2 == 1) || (i % 2 == -1)) sum = sum + i; 
	}
	cout << sum << endl;
	return 0;
}
