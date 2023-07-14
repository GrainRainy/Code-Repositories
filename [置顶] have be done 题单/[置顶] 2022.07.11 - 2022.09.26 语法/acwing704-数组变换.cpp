#include <bits/stdc++.h>
using namespace std;

int a[25];
int main()
{
	int cnt = 0;
	for (int i = 1; i <= 20; i ++)
		cin >> a[i];
		
	for (int i = 20; i > 0; i --)
	{
		printf("N[%d] = %d\n",cnt,a[i]);
		cnt ++;
	}
		
	
	return 0;
}
