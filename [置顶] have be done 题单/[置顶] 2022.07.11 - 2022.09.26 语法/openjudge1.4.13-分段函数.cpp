#include<bits/stdc++.h>
using namespace std;
int main()
{
	float x;
	cin>>x;
	float m;
	if(x>=0&&x<5) m=-x+2.5;
	else if(x>=5&&x<10) m=2-1.5*(x-3)*(x-3);
	else if(x>=10&&x<20) m=x/2-1.5;
	printf("%.3f",m);
	return 0;
} 
