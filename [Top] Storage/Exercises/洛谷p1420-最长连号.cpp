#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;//���ݸ��� 
	cin>>n; 
	long long x;//ѭ���������
	int a=-1;//�洢�ϴ�ѭ���������ж�����
	int sum=1;//���Ÿ���
	int save=0;//�洢�������Ÿ����ԱȽϴ�С 
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
