#include<bits/stdc++.h>
using namespace std;
int main()
{
	int max=0,min=10000;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x>max) max=x;
		if(x<min) min=x;
		
	}
	cout<<max-min;
} 
