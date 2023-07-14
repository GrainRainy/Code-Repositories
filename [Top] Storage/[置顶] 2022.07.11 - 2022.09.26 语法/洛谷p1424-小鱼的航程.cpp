#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,n,sum=0;
	cin>>x>>n;
	for(int i=x;i<x+n;i++)
	{
		if(i%7!=6&&i%7!=0)
		sum=sum+250;
	}
	cout<<sum;
	return 0;
}
