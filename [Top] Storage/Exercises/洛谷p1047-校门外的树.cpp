#include<bits/stdc++.h>
using namespace std;
bool a[10005];//未移走的树为0; 
int main()
{
	int l,m;
	cin>>l>>m;
	int u,v;
	int sum=0;//还活着的树 
	for(int j=1;j<=m;j++)
	{
		cin>>u>>v;
		for(int i=u;i<=v;i++)
		a[i]=1;
	} 
	for(int k=0;k<=l;k++)
	if(a[k]==0) sum++;
	cout<<sum;
	return 0;
}
