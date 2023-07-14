#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long m,t,s;
	scanf("%ld %ld %ld",&m,&t,&s);
	if(t==0)
	{
		cout<<0;
		return 0;
	}
	int a;
	a=m-ceil(s*1.0/t);
	if(a<0)
		cout<<0;
	else
	printf("%ld",a);
	return 0;
}
