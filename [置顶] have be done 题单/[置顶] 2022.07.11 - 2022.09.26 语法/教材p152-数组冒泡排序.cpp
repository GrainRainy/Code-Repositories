#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int save;//存放临时数据
	for(int j=1;j<n;j++)
	{
		for(int i=1;i<n;i++)
		{
			if(a[i]>a[i+1])
			{
				save=a[i+1];
				a[i+1]=a[i];
				a[i]=save;
			}
		} 
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
