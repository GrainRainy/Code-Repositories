#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n --)
	{
		int a,b;
		int sum = 0;
		cin >> a >> b;
		if (a > b) swap(a,b);
		
		for (int i = a + 1;i < b;i ++)
		{
			if (i % 2) sum += i;
		}
		cout << sum << endl;
	}
}
