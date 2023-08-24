#include<bits/stdc++.h>
using namespace std;
int n,a[5010][5010],tot=1;
int main()
{
	cin>>n;
	int i=1,j=1;
	a[1][1]=tot;
	while(tot<n*n)
	{
	while(j+1<=n&&!a[i][j+1]) a[i][++j]=++tot;
	while(i+1<=n&&!a[i+1][j]) a[++i][j]=++tot;
	while(j-1>=1&&!a[i][j-1]) a[i][--j]=++tot;
	while(i-1>=1&&!a[i-1][j]) a[--i][j]=++tot;
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++){
    	 printf("%-5d",a[i][j]);
    }
    cout<<endl;
}
return 0;
}
