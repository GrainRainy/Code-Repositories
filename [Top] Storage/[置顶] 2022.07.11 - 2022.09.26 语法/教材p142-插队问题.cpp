#include<bits/stdc++.h>
using namespace std;
int p[105];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int x;
	cin>>x;
	int g=p[n];
	for(int j=n;j>x;j--)
		p[j]=p[j-1]; 
	p[x]=g;
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	return 0; 
}
