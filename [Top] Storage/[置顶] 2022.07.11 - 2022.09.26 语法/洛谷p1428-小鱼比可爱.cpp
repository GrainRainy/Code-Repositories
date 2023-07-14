#include<bits/stdc++.h>
using namespace std;
int a[105];//numbers of fish
int sum[105];//不如自己可爱的鱼的个数
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j]<a[i]) sum[i]++;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<sum[i]<<" ";
	return 0;
} 
