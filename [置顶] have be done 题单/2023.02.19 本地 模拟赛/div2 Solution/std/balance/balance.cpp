#include<bits/stdc++.h>
using namespace std;
int n;
int s[510];
bool f[20002];
int ans=0;
int maxx=0;
int main()
{
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		ans+=s[i];
	}
	f[0]=1;
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=ans;j>=1;j--)
		{
			if(j-s[i]>=0&&f[j-s[i]]==1)
			{
				f[j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=ans;j++)
		{
			if(f[j+s[i]]==1)
			{
				f[j]=1;
			}
		}
	}
	for(int i=1;i<=ans;i++)
	{
		if(f[i]) maxx++;
	}
	cout<<maxx<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
