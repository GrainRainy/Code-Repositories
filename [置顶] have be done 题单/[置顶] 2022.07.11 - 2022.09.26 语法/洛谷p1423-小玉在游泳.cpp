#include<bits/stdc++.h>
using namespace std;
int main()
{
	float s;
	cin>>s;
	int times=1;
	double i=2;
	for(i;i<s;)
	{
		times++;
		i=i+2*pow(0.98,times-1);
	}
	cout<<times;

	return 0;
} 
