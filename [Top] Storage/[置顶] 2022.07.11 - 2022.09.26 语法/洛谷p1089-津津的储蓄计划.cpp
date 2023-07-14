#include<bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
	int save=0;//存的钱 
	int money=0;//手上现有的钱 
	for(int i=1;i<=12;i++)
		cin>>a[i];
	for(int i=1;i<=12;i++)
	{
		money=money+300-a[i];//i月末剩余 
		if(money<0)
		{
			cout<<"-"<<i;
			return 0;
		}
		save=save+money/100;//等会输出时记得*100 
		money=money%100;
	}
	cout<<save*120+money;
	return 0;
}
