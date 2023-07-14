#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x;
	double k;
	int num=n*1.0/364;
	for(x=100;x>=1;x--)
	{
		k=(num-x)*1.0/3;
		if(k-(int)k==0&&k>0) break;
	}
	cout<<x<<endl<<k<<endl;
	return 0;
} 
