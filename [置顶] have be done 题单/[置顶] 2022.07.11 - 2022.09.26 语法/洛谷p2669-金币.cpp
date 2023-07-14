#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	cin>>k;
	int sum=0;
	int i=1;
	int n=1;
	for(n;n<=k;i++)
	{
		for(int j=1;j<=i&&n<=k;j++)
		{
			sum=sum+i; 
			n++;
		}
	} 
	cout<<sum;
	return 0;
}  
