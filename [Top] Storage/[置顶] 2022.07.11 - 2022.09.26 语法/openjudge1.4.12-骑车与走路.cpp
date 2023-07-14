#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s;
	cin>>s;
	float tw,tr;//second
	tw=s/1.2;
	tr=s/3.0+50;
	if(tw>tr) cout<<"Bike";
	if(tw==tr) cout<<"All";
	if(tw<tr) cout<<"Walk";
	return 0;
} 
