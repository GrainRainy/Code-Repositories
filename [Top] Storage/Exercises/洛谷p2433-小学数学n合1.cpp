#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	
	scanf("%d",&a);
	if(a==1)
		printf("%s","I love Luogu!");
	else if(a==2)
		printf("%d %d",6,4);
	else if(a==3)
		printf("%d\n%d\n%d",14/4,14-14%4,14%4);
	else if(a==4)
		printf("%.3f",500.0/3);
	else if(a==5)
		printf("%d",15);
	else if(a==6)
		cout<<sqrt(pow(6,2)+pow(9,2));
	else if(a==7)
		printf("%d\n%d\n%d\n",110,90,0);
	else if(a==8)
		cout<<10*3.141593<<endl<<25*3.141593<<endl<<pow(5,3)*3.141593*4/3;
	else if(a==9)
		cout<<22;
	else if(a==10)
		cout<<9;
	else if(a==11)
		cout<<100.0/3;
	else if(a==12)
	{
	
		char A='A',M='M';
		cout<<(int)(M-A+1)<<endl<<(char)(A+18-1);
	}
	else if(a==13)
	{
		double v,l;
		v=pow(4,3)*3.141593*4/3+pow(10,3)*3.141593*4/3;
		l=pow(v,1.0/3);
		cout<<(int)l;
	}
	else if(a==14)
		cout<<50;
	
		
	return 0;
}
