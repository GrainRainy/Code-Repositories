#include<bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
	int save=0;//���Ǯ 
	int money=0;//�������е�Ǯ 
	for(int i=1;i<=12;i++)
		cin>>a[i];
	for(int i=1;i<=12;i++)
	{
		money=money+300-a[i];//i��ĩʣ�� 
		if(money<0)
		{
			cout<<"-"<<i;
			return 0;
		}
		save=save+money/100;//�Ȼ����ʱ�ǵ�*100 
		money=money%100;
	}
	cout<<save*120+money;
	return 0;
}
