#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans;
	cin>>n;
	while(n)
	{
		ans=ans*10+n%10;
		n=n/10;
	}
	cout<<ans;
	return 0;
}
