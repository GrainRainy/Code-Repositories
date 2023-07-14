#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	int m;
	cin>>m;
	for (int k=1;k<=n;k++)
	{
		if(a[k]==m) ans++;
	}
	cout<<ans;
	return 0;
}
