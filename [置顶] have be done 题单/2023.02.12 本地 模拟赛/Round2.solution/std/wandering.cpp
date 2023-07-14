#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[2][N];
int cnt;
int main(){
	freopen("wandering.in","r",stdin);
	freopen("wandering.out","w",stdout);
	int n,T;
	scanf("%d%d",&n,&T);
	int r,c;
	while(T--){
		scanf("%d%d",&r,&c);
		--r;
		if(a[r][c]==1&&a[r^1][c]==1) --cnt;
		else if(a[r][c]==0&&a[r^1][c]==1) ++cnt;
		a[r][c]^=1;
		puts(cnt?"NO":"YES");
	}
	return 0;
} 
