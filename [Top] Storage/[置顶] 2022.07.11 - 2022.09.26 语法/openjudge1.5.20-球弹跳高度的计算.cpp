#include<bits/stdc++.h>
using namespace std;
int main()
{
	double h;
	cin>>h;
	double sum=h;
	double x=0;
	for(int i=1;i<=10;i++)
	{
		sum=sum+x*2;
		x=h*1.0/2;
		h=x;
		
	}
	cout<<sum<<endl<<x;
	return 0;
} 
