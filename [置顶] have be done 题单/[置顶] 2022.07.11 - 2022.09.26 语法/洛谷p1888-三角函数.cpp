#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	int k=(a>b)?a:b;
	int n=(k>c)?k:c;//the bigest;
	int l=(a<b)?a:b;
	int m=(l<c)?l:c;//the smallest;
	for(int i=2;i<=sqrt(m);i++)
	{
		if(m%i==0&&n%i==0)
		{
			m=m/i;
			n=n/i;
		}
	}
	cout<<m<<"/"<<n;
	return 0;
}
