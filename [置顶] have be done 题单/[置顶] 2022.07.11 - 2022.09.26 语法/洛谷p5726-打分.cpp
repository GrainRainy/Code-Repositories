#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	int n;
	int sum=0;
	cin>>n;
	int min=11,max=-1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(min>a[i]) min=a[i];
		if(max<a[i]) max=a[i];
	}
	for(int i=1;i<=n;i++)
		sum=sum+a[i];
	sum=sum-max-min;
	double score;
	score=sum*1.0/(n-2);
	printf("%.2lf",score);
	return 0;
}
