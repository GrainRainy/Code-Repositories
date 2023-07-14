#include<iostream>
#include<cstdio>
#include<cstring>
#include<unordered_map>
#define N 55
#define M 10000000
#define int unsigned int
#define ll unsigned long long
using namespace std;
namespace ywy{
    unordered_map<int,ll> f,g;ll s[N];char h[M];
    void ywymain(){
    	freopen("npc.in","r",stdin);
    	freopen("npc.out","w",stdout);
        int t;cin>>t;while(t){
            t--;int n,m;cin>>n>>m;for(register int i=0;i<n;i++)s[i]=0;
            for(register int i=1;i<=m;i++){
            	int a,b;cin>>a>>b;a--;b--;s[a]|=(1ll<<b);s[b]|=(1ll<<a);	
            }if(n==1){
                cout<<1<<endl;continue; 
            }int dk=(n/2)+(n&1);f.clear();g.clear();
            for(register int i=0;i<n/2;i++)f[1<<i]=s[i];
            int mx=0;for(register int i=0;i<(1<<(n/2));i++){
                h[i]=0;for(register int j=0;j<n/2;j++){
                    if(i&(1ll<<j))h[i]=max(h[i],h[i-(1ll<<j)]); 
                }if(!f.count(i))continue;int cnt=0;ll me=f[i];
                for(register int j=0;j<n/2;j++){
                    if(me&(1ll<<j))f[i|(1ll<<j)]=me&s[j];
                    if(i&(1ll<<j))cnt++;
                }h[i]=cnt;mx=max(mx,cnt);
            }for(register int i=n/2;i<n;i++)g[1<<(i-n/2)]=s[i];
            for(register int i=0;i<(1<<dk);i++){
                if(!g.count(i))continue;int cnt=0;ll me=g[i];for(register int j=0;j<dk;j++){
                    if(i&(1<<j))cnt++;
                    if(me&(1ll<<(j+n/2)))g[i|(1<<j)]=me&s[j+n/2];
                }mx=max(mx,cnt+h[me&((1<<(n/2))-1)]);
            }cout<<mx<<endl;
        }
    }
}
signed main(){
    ywy::ywymain();return(0);
}
