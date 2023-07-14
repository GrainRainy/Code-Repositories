#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x1,y1;
	cin>>x1>>y1;
	double x2,y2;
	cin>>x2>>y2;
	double dis=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	printf("%.4f",dis); 
	return 0;
}
