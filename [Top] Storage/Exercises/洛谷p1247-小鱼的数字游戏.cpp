#include<bits/stdc++.h>
using namespace std;
int a[105]; 
int main()
{
	int x;
	int i=1;
	for(i;i!=0;i++)
	{
		cin>>x;
		if(x==0) break;
		a[i]=x;
	}
	for (int k=i-1;k>=1;k--)
	cout<<a[k]<<" ";
	return 0;
} 
