#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10;
	scanf("%c-%c%c%c-%c%c%c%c%c-%c",&ch1,&ch2,&ch3,&ch4,&ch5,&ch6,&ch7,&ch8,&ch9,&ch10);
	int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
	a1=ch1-'0';
	a2=ch2-'0';
	a3=ch3-'0';
	a4=ch4-'0';
	a5=ch5-'0';
	a6=ch6-'0';
	a7=ch7-'0';
	a8=ch8-'0';
	a9=ch9-'0';
	int isbn;
	isbn=a1*1+a2*2+a3*3+a4*4+a5*5+a6*6+a7*7+a8*8+a9*9;
	if(ch10=='X')
		a10=10;
	else
		a10=ch10-'0';
	if(isbn%11==a10)
		cout<<"Right";
	else
	{
		if(isbn%11!=10)
		cout<<a1<<"-"<<a2<<a3<<a4<<"-"<<a5<<a6<<a7<<a8<<a9<<"-"<<isbn%11;
		else
		cout<<a1<<"-"<<a2<<a3<<a4<<"-"<<a5<<a6<<a7<<a8<<a9<<"-"<<"X";
	}
	return 0;
}
