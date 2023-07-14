#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	double ex=((pow((1+sqrt(5))/2,n))-(pow((1-sqrt(5))/2,n)))/sqrt(5);
	printf("%.2lf",ex);
	return 0;
 } 
