#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	cin>>k;
	int n1=1,n2=1,n3;
	if(k==1)cout<<"1";
	else if(k==2)cout<<"1";
	else
	{
		for(int i=3;i<=k;i++)
	{
		n3=n1+n2;
		n1=n2;
		n2=n3;
	 } 
	cout<<n3;
	 } 
	
	return 0;
} 
