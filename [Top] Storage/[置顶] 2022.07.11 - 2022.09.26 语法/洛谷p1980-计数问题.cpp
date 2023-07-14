#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x;
	int sum=0;
	cin>>n>>x;
	for(int i;i<=n;i++)
	{
		int a=i;
		for(;a!=0;) 
		{
			if(a%10==x) sum++;
			a=a/10;
		}
	}
	cout<<sum;
	return 0;
}
