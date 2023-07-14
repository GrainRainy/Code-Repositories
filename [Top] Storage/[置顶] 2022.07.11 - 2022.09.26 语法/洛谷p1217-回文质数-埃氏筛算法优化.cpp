#include<bits/stdc++.h>
using namespace std;
bool prime[100000005];
int main()
{
	int a,b;
	cin>>a>>b;
	if(b>10000000) b=10000000;
	for (int i=2;i<=sqrt(b);i++)
	{
		if(!prime[i])
		{
			for(int j=i;j*i<=b;j++)
			prime[i*j]=1;
		}
	}
	for(int i=a;i<=b;i++)
	{
		if(!prime[i])
		{
			int s=0,x=i;
			while(x)
			{
				s=s*10+x%10;
				x=x/10;
			}
			if(s==i) printf("%d\n",i);
		}
	}
	return 0;
}
