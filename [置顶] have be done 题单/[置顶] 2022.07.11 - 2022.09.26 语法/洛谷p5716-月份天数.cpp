#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a%400==0||(a%4==0&&a%100!=0))
	{
		switch(b)
		{
			case 1:case 3:case 5:case7:
			case 8:case 10:case 12:    
				cout<<"31";
			break;
			case 2:cout<<"29";break;
			default:cout<<"30"; 
		}
	}
	else
	{
		switch(b)
		{
			case 1:case 3:case 5:case 7:
			case 8:case 10:case 12:    
				cout<<"31";
			break;
			case 2:cout<<"28";break;
			default:cout<<"30"; 
		}
	}
	return 0;
}
