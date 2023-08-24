#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i;
	long long x=0;
	cin>>i;
	if(i!=1)
	{
		for(i;x!=1;)
		{
			if(i%2==0)
			{
				x=i/2;
				cout<<i<<"/2="<<x<<endl;
				i=x;
			}
			else
			{
				x=i*3+1;
				cout<<i<<"*3+1="<<x<<endl;
				i=x;
			}
		}
	}
	cout<<"End";
	return 0;
} 
