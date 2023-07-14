#include <bits/stdc++.h>
using namespace std;
long long a[70];
int main()
{
	int n;
	cin >> n;
	
	a[0] = 0;
	a[1] = 1;
	for(int i = 2; i <= 65; i ++)
		a[i] = a[i - 1] + a[i - 2];
	 
	while (n --)
	{
			int x;
			cin >> x;
			printf("Fib(%d) = %ld\n",x,a[x]);
	}
	
	return 0;
}
