#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
const int mod=998244353;
int ad(int x,int y){
	return (x+y)>=mod?(x+y-mod):x+y;
}
int mul(int x,int y){
	return (ll)x*y%mod;
}
int qm(int x,int y=mod-2){
	int ret=1;
	while(y){
		if(y&1) ret=mul(ret,x);
		x=mul(x,x);
		y>>=1;
	}
	return ret;
}
int jie[N],inv[N];
int C(int n,int m){
	if(n<m) return 0;
	return mul(jie[n],mul(inv[m],inv[n-m]));
}
int n,m;
int main(){
	freopen("umbrella.in","r",stdin);
	freopen("umbrella.out","w",stdout);
	scanf("%d%d",&n,&m);
	//C(m-1,n-1)*2^(n-1)
	jie[0]=1;
	for(int i=1;i<=m;++i) jie[i]=mul(jie[i-1],i);
	inv[m]=qm(jie[m]);
	for(int i=m-1;i>=0;--i) inv[i]=mul(inv[i+1],i+1);
	cout<<mul(C(m-1,n-1),qm(2,n-1));
	return 0;
}
