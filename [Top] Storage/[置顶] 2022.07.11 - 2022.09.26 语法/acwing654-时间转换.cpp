#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h,min;
	int n;
	cin>>n;
	h=n/3600;
	n=n%3600;
	min=n/60;
	n=n%60;
	printf("%d:%d:%d",h,min,n);
	return 0;
}
