#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	if(n==1) cout<<"1";
	else if(n==2) cout<<"2";
	else if(n==3) cout<<"3";
	else
	{
		for (int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			cout<<n/i;break;
		 } 
		else continue;
	}
	}
	
	return 0; 
}
