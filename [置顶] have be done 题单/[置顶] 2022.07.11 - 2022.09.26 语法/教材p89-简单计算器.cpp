#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	char c;
	scanf("%d%c%d",&a,&c,&b);
	switch(c)
	{
		case '+':cout<<a<<"+"<<b<<"="<<a+b;break;
		case '-':cout<<a<<"-"<<b<<"="<<a-b;break;
		case '*':cout<<a<<"*"<<b<<"="<<a*b;break;
		case '/':
			{
			if(b==0)
				cout<<"Divided by zero";
			else
				cout<<a<<"/"<<b<<"="<<a/b;break;
			}
			
		default:cout<<"Invalid operator";
	}
	return 0;
}

