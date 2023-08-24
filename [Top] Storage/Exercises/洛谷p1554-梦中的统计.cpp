#include<bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=m;i<=n;i++)
	{
		for(int j=i;j>0;)
		{
			a[j%10]++;
			j=j/10;
		}
	}
	for(int b=0;b<=9;b++)
	cout<<a[b]<<" ";
}
