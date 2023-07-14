#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int y,m,d;
	y=n/365;
	n=n%365;
	m=n/30;
	n=n%30;
	d=n;
	printf("%d ano(s)\n",y);
	printf("%d mes(es)\n",m);
	printf("%d dia(s)\n",d);
	return 0;
}
