#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s,v;//路程和速度 
	cin>>s>>v;
	int t;//所需总分钟数 
	t=ceil(s*1.0/v);
	int h,m;//所需小时和分钟 
	int outh,outm;//输出小时和分钟 
	h=t/60;
	m=t%60;
	if(h<7)//未提前一天 
	{
		if(m<=50)//分钟无需借位 
		{
			outh=7-h;
			outm=50-m;
		} 
		else//分钟需借位 
		{
			outh=7-h-1;
			outm=50+60-m;
		}
	}
	else if(h==7)
	{
		if(m<=50)//分钟无需借位 
		{
			outh=7-h;
			outm=50-m;
		} 
		else//分钟需借位 
		{
			outh=24+7-h-1;
			outm=50+60-m;
		}
	}
	else//提前一天 
	{
		if(m<=50)//分钟无需借位 
		{
			outh=24+7-h;
			outm=50-m;
		}
		else//分钟需借位 
		{
			outh=24+7-h-1;
			outm=50+60-m;
		}	
	}
	if(outh<10)//输出小时补0 
	{
		if(outm<10)//输出小时和分钟都补0 
			cout<<"0"<<outh<<":"<<"0"<<outm<<endl;
		else//输出小时补0，输出分钟不补0 
			cout<<"0"<<outh<<":"<<outm<<endl;
	}
	else//输出小时不补0 
	{
		if(outm<10)//输出小时不补0，分钟补0 
			cout<<outh<<":"<<"0"<<outm<<endl;
		else//输出小时和分钟都不补0 
			cout<<outh<<":"<<outm<<endl;
	}
	return 0;
}
