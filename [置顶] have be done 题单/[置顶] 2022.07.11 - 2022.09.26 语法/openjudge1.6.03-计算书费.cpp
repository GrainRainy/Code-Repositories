#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10];
	float sum=0;
	for(int i=1;i<=10;i++)
	cin>>a[i];
	float b[20]={0,28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
	for(int j=1;j<=10;j++)
	sum=sum+a[j]*b[j];
	printf("%.1f",sum); 
	return 0;
 } 
