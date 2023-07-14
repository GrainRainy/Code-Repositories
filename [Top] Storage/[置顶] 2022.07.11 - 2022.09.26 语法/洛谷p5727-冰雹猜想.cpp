#include<bits/stdc++.h>
using namespace std;
int a[500];
int main()
{
	int n;
	cin>>n;
	if(n==1) cout<<"1";
	else
	{
			a[1]=n;
	for(int i=2;i>0;i++)
	{
		if(a[i-1]%2==1) a[i]=a[i-1]*3+1;
		else a[i]=a[i-1]/2;
		if(a[i]==1) break;
	}
	for(int i=500;i>=1;i--)
	{
		if(a[i]==0) continue;
		else cout<<a[i]<<" ";
	}
	}
	return 0;
} 
