#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int a,b,c,d;
	cin>>n;
	a=(n%2==0&&n>4&&n<=12);
	b=(n%2==0||n>4&&n<=12);
	d=(n%2!=0&&(n<=4||n>12));
	if(n%2==0&&n>4&&n<=12) c=0;
	else if(n%2!=0&&(n<=4||n>12)) c=0;
	else c=1; 
	printf("%d %d %d %d",a,b,c,d);
	return 0;	
}
