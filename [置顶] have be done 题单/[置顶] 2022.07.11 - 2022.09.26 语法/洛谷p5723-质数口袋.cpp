#include<bits/stdc++.h>
using namespace std;
int main()
{
	int L;
	cin>>L;
	if(L==1)
	{
		cout<<"0"<<endl;
		//return 0;
	}
	else if(L>=2&&L<5)
	{
		cout<<"2"<<endl<<"1"<<endl;
		//return 0;
	}
	else
	{
		int sum=5;
	int num=2;
	cout<<"2"<<endl; 
	cout<<"3"<<endl;
	int i;
	int j;
	for(i=4;sum+i<=L;i++)
	{
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0) break;
		}
		if(i%j!=0)
		{
			sum=sum+i;
			num++;
			cout<<i<<endl;
		}
		
	}
	cout<<num;
	}
	
	return 0;
}  
