#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int inf=0x3f3f3f3f;
int a[N];
int f[N][N];
int g[N][N];
int n;
int main(){
//	freopen("revenant.in","r",stdin);
//	freopen("revenant.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) {
		f[i][i]=1;g[i][i]=a[i];
	}
	for(int l=2;l<=n;++l){
		for(int i=1;i+l-1<=n;++i){
			int j=i+l-1;
			f[i][j]=inf;
			for(int k=i;k<j;++k){
				int now;
				if(f[i][k]==1&&f[k+1][j]==1 && g[i][k]==g[k+1][j])
					f[i][j]=1,g[i][j]=g[i][k]+1;
				else
					f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
			}
		}
	}
	cout<<f[1][n];
	return 0;
}
