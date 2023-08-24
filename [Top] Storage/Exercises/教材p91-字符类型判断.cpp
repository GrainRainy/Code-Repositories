#include<bits/stdc++.h>
using namespace std;
int main ()
{
	char a;
	cin>>a;
	if (a>='a'&&a<='z')
		cout<<"lowercase";
	else if('a'>='A'&&'a'<='Z')
		cout<<"capital";
	else if('a'>='1'&&a<='9')
		cout<<"number";
	else 
		cout<<"others";
		return 0;
}
