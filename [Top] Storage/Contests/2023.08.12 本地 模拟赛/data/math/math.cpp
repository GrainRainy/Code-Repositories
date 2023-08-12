#include <bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;

#define int long long 
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

tr1::unordered_map<int,int>m2;

const int N=5e6+10,mod=998244353;
int mu[N],cnt,vis[N],pri[N],block=N-10,phi[N],n,k;

void get(int n)
{
	phi[1]=mu[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vis[i]) phi[i]=i-1,pri[++cnt]=i;
		for(int j=1;j<=cnt&&i*pri[j]<=n;++j)
		{
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)
			{
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			else 
			{
				phi[i*pri[j]]=phi[i]*(pri[j]-1);
			}
		}
	}
	for(int i=1;i<=n;++i)
		phi[i]+=phi[i-1];
}

int get_phi(int n)
{
	if(n<=block)return phi[n];
    if(m2[n])return m2[n];
    int ans=n*(n+1)/2;
    for(int l=2,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        ans-=(r-l+1)*get_phi(n/l); 
    } 
    return m2[n]=ans;
}

int qpow(int a,int b) {
	int x(1);
	while(b) {
		if(b&1) x=x*a%mod;
		a=a*a%mod,b>>=1;
	}
	return x;
}
int jc[20],rj[20];
int C(int a,int b) {
	if(a<b) return 0;
	return jc[a]*rj[b]%mod*rj[a-b]%mod;
}
int sum(int r,int k) {
	int ans=0;
	for(int i=0,u=0,t;i<=k;++i,u^=1) {
		t=qpow(2,k-i);
		if(t==1) {
			ans=u?(ans-r):ans+r;
			ans=(ans+mod)%mod;
			continue;
		}
		if(!u)
			ans=(ans+C(k,i)*(qpow(t,r+1)-t+mod)%mod*qpow(t-1,mod-2)%mod)%mod;
		else
			ans=(ans-C(k,i)*(qpow(t,r+1)-t+mod)%mod*qpow(t-1,mod-2)%mod)%mod;
	}
	return ans;
}
signed main()
{
//	freopen("math.in","r",stdin);
//	freopen("math.out","w",stdout);
	int T;cin>>T;
	jc[0]=1;
	for(int i=1;i<=15;++i)
		jc[i]=jc[i-1]*i%mod;
	rj[15]=qpow(jc[15],mod-2);
	for(int i=14;i>=0;--i)
		rj[i]=rj[i+1]*(i+1)%mod;
    get(block);
    while(T--)
    {
    	int ans=0;
    	n=read(),k=read();
    	for(int l=1,r,s=0,t;l<=n;l=r+1)
		{
			r=n/(n/l);
			t=sum(r,k);
			ans=(ans+(2*get_phi(n/(l))-1)%mod*((t-s+mod)%mod))%mod;
			s=t;
		}
		cout<<ans<<endl;
    }
	return 0;
}