#include<bits/stdc++.h>
using namespace std;
int f[35],n;
int main()
{
	cin>>n;
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=n;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;
}
