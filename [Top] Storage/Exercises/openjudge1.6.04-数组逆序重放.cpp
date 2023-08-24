#include<bits/stdc++.h>
using namespace std;
int a[102];
int main()
{
	int n;
	cin>>n;
	int i=1;
	for (i;i<=n;i++)
	cin>>a[i];
	for (int j=i-1;j>=1;j--)
	cout<<a[j]<<" ";
	return 0; 
}
