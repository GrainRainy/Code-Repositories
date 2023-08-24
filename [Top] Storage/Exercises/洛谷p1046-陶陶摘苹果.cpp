#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10];
	int n;
	int sum=0;
	for(int i=1;i<=10;i++)
	cin>>a[i];
	cin>>n;
	for(int j=1;j<=10;j++)
	{
		if(n+30>=a[j]) sum++;
	}
	cout<<sum;
	return 0;
 } 
