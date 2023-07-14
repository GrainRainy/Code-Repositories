#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	cin>>k;
	double s=0;
	int i=1;
	for(i=1;i!=0;i++)
	{
		s=s+1.0/i;
		if(s>k) break;
		
	}
	cout<<i;
	return 0;
}
