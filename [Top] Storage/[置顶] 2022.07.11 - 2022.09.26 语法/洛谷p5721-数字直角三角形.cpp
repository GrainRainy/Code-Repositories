#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int sum=0;
	int k=n;
	for(int i=1;i<=n;i++)
	{
		for(int j=k;j>=1;j--)
		{
			sum++;
			if(sum<10) cout<<"0"<<sum;
			else cout<<sum;
		}
		k--;
		cout<<endl;
	}
	return 0;
}
