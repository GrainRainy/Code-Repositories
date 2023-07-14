#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;//数据个数 
	cin>>n; 
	long long x;//循环输入的数
	int a=-1;//存储上次循环的数以判断连数
	int sum=1;//连号个数
	int save=0;//存储上组连号个数以比较大小 
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(a+1==x)
		{
			sum++;
		//cout<<sum<<endl;
		 } 
		else 
		{
			if(sum>save) 
			{
				save=sum;
		        sum=1;
			}
		}
		
		a=x;
	 } 
	if(sum>save) save=sum;
	cout<<save;
	
}
