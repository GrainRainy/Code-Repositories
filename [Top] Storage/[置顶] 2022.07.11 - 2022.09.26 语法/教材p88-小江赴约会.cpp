#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	switch(a)
	{
		case 1:
		case 3:
		case 5:cout<<"NO";break;
		case 2:
		case 4:
		case 6:
		case 7: cout<<"YES";break;
		default:cout<<"Error";
	} 
	return 0;
}
