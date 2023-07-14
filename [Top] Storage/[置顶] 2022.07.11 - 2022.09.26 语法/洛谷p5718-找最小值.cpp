#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int suma=0,ta=0,sumb=0,tb=0;
	for(int i=1;i<=n;i++)
	{
		if(i%k==0)
		{
			suma=suma+i;
			ta++;
		}
		else
		{
			sumb=sumb+i;
			tb++;
		}
	}
	double a,b;
	a=suma*1.0/ta;
	b=sumb*1.0/tb;
	printf("%.1f %.1f",a,b);
	return 0;
}
