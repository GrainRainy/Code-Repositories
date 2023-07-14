#include<bits/stdc++.h>
using namespace std;
bool a[105]; //n个小朋友的标记 
int main()
{
	int n,m;
	cin>>n>>m;
	int x=0;
	int p=0;
	for(int i=1;i>0;i++)
	{
		if(p>=n) break;
		if(i==n+1) i=1;
		if(a[i]==1) continue;
		x++;
		if(x==m+1) x=1;
		if(x==m)
		{
			a[i]=1;
			cout<<i<<" ";
			p++;
		}
	}
	return 0;
}
