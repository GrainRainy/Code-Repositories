#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	bool a,b;
	cin>>n;
	a=n%2==0;
	b=(n>4&&n<=12);
	printf("%d %d %d %d",a&&b,a||b,a==!b,!a&&!b);
	return 0;	
}
