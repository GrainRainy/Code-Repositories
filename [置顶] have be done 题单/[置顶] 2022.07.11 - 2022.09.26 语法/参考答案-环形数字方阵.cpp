#include<bits/stdc++.h>//n<=5000
using namespace std;
int a[5010][5010];
int main()
{
	int n;
	cin>>n;
	int i=1,j=1;
	int tot=1;
	a[1][1]=tot;
	while(j+1<=n) a[i][++j]=++tot;
	while(i+1<=n) a[++i][j]=++tot;
	while(j-1>=1) a[i][--j]=++tot;
	while(i-1>=1) a[--i][j]=++tot;
	a[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		{	 cout<<a[i][j]<<" ";
	     }
  
  cout<<endl;
}
  return 0;
}
