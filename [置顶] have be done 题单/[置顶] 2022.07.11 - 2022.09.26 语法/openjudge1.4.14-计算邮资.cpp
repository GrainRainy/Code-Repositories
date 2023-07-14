#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	char b;
	cin>>a;
	cin>>b;
	int m;//money
	if(a<=1000) m=8;
	else if(a>1000) m=8+ceil((a-1000)*1.0/500)*4;
	if (b=='y') m=m+5; 
	cout<<m;
	return 0;
} 
