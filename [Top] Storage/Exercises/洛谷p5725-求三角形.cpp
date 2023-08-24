#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int k=1;//矩形输出值 
	int m=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(k<10) cout<<"0"<<k;
			else cout<<k;
			k++; 
		}
	cout<<endl;
	}
	cout<<endl;
	int t=1;//三角形输出值 
	for (int a=1;a<=n;a++)
	{	for (int q=1;q<=2*n-2*a;q++)
		cout<<" ";
		for (int b=1;b<=a;b++)
		{
			if (t<10) cout<<"0"<<t;
			else cout<<t;
			t++;
		}
		cout<<endl;
	}
	
	return 0;
}
