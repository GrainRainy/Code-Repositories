#include<bits/stdc++.h>
using namespace std;
int t[105][105],x[105][105];
int main()
{
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			cin>>x[i][j];
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			cout<<t[i][j]+x[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
