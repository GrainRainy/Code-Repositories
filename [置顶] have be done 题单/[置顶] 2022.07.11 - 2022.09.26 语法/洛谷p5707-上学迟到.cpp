#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s,v;//·�̺��ٶ� 
	cin>>s>>v;
	int t;//�����ܷ����� 
	t=ceil(s*1.0/v);
	int h,m;//����Сʱ�ͷ��� 
	int outh,outm;//���Сʱ�ͷ��� 
	h=t/60;
	m=t%60;
	if(h<7)//δ��ǰһ�� 
	{
		if(m<=50)//���������λ 
		{
			outh=7-h;
			outm=50-m;
		} 
		else//�������λ 
		{
			outh=7-h-1;
			outm=50+60-m;
		}
	}
	else if(h==7)
	{
		if(m<=50)//���������λ 
		{
			outh=7-h;
			outm=50-m;
		} 
		else//�������λ 
		{
			outh=24+7-h-1;
			outm=50+60-m;
		}
	}
	else//��ǰһ�� 
	{
		if(m<=50)//���������λ 
		{
			outh=24+7-h;
			outm=50-m;
		}
		else//�������λ 
		{
			outh=24+7-h-1;
			outm=50+60-m;
		}	
	}
	if(outh<10)//���Сʱ��0 
	{
		if(outm<10)//���Сʱ�ͷ��Ӷ���0 
			cout<<"0"<<outh<<":"<<"0"<<outm<<endl;
		else//���Сʱ��0��������Ӳ���0 
			cout<<"0"<<outh<<":"<<outm<<endl;
	}
	else//���Сʱ����0 
	{
		if(outm<10)//���Сʱ����0�����Ӳ�0 
			cout<<outh<<":"<<"0"<<outm<<endl;
		else//���Сʱ�ͷ��Ӷ�����0 
			cout<<outh<<":"<<outm<<endl;
	}
	return 0;
}
