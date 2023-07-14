#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,k;
	cin>>m>>k;
	int a=0,b=0;// 0 or 1
	int sum=0;
	if(m%19==0) a=1;
	for(int i;m!=0;)
	{
		i=m%10;
		if(i==3) sum++;
		m=m/10;
	}
	if(sum==k) b=1;
	if(a==1&&b==1) cout<<"YES";
	else cout<<"NO";
	return 0;
}
