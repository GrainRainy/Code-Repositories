#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define N 2222
#define M 10000000
#define ls(_o) (_o<<1)
#define rs(_o) ((_o<<1)|1)
#define inf 1000000000000000001ll
#define safe_add(_a,_b) min(inf,(_a)+(_b))
using namespace std;
namespace ywy{
    typedef struct _qj{
        int l;int r;ll val;
        friend bool operator <(const _qj &a,const _qj &b){
            return(a.val<b.val);    
        }
    }qj;qj qjs[N*N];ll ints[N];int pos[N][N];vector<int> vec[N],op[N];vector<ll> u[N];
    ll anss[300100];int mx[M];
    void setpt(int l,int r,int tree,int pt,int x){
        mx[tree]=max(mx[tree],x);if(l==r)return;int mid=(l+r)>>1;
        if(pt<=mid)setpt(l,mid,ls(tree),pt,x);else setpt(mid+1,r,rs(tree),pt,x);
    }
    int query(int rl,int rr,int l,int r,int tree){
        if(rl==l&&rr==r)return(mx[tree]);int mid=(l+r)>>1;
        if(rl>mid)return(query(rl,rr,mid+1,r,rs(tree)));if(rr<=mid)return(query(rl,rr,l,mid,ls(tree)));
        return(max(query(rl,mid,l,mid,ls(tree)),query(mid+1,rr,mid+1,r,rs(tree)))); 
    }
    void ywymain(){
    	freopen("gold.in","r",stdin);
    	freopen("gold.out","w",stdout);
        int n,m;cin>>n>>m;for(register int i=1;i<=n;i++)cin>>ints[i];
        int ptr=1;for(register int i=1;i<=n;i++){
            ll tot=0;for(register int j=i;j<=n;j++){
                tot=safe_add(tot,ints[j]);qjs[ptr].val=tot;qjs[ptr].l=i;qjs[ptr].r=j;ptr++;  
            }
        }ptr--;sort(qjs+1,qjs+1+ptr);for(register int i=1;i<=ptr;i++)pos[qjs[i].l][qjs[i].r]=i;
        memset(anss,0x7f,sizeof(anss));for(register int i=1;i<=m;i++){
            int l,r;ll u;scanf("%d%d%lld",&l,&r,&u);vec[r].push_back(l);op[r].push_back(i);
            ywy::u[r].push_back(u);
        }for(register int i=1;i<=n;i++){
            for(register int j=1;j<=i;j++){
                setpt(1,ptr,1,pos[j][i],j);
            }for(register int j=0;j<vec[i].size();j++){
                int ans=0,l=1,r=ptr;while(l<=r){
                    int mid=(l+r)>>1;if(qjs[mid].val<=u[i][j])ans=mid,l=mid+1;else r=mid-1; 
                }if(!ans)continue;int pos=ans;r=ans;ans=0;l=1;while(l<=r){
                    int mid=(l+r)>>1;if(query(mid,pos,1,ptr,1)>=vec[i][j])ans=mid,l=mid+1;else r=mid-1; 
                }if(!ans)continue;anss[op[i][j]]=qjs[ans].val; 
            }
        }for(register int i=1;i<=m;i++){
            if(anss[i]==anss[0])printf("0\n");else printf("%lld\n",anss[i]); 
        }
    }
}
int main(){
    ywy::ywymain();return(0);   
}
