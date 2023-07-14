#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	int min = 21474;
	for (int i = 0; i < n; i ++)
	{
		cin >> a[i];
		if (a[i] < min)
		{
			min = a[i];
			cnt = i;
		}
		 
	}
	
	printf("Minimum value: %d\n",min);
	printf("Position: %d",cnt);
	return 0;
}
