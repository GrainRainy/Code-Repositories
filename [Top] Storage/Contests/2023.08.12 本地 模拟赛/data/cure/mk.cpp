#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    return s*w;
}
void input()
{
    int lim=998244353,k=1e3;
    int d=500000;
    int n=d-rand()%(d/10),u=rand()%lim+1,v=rand()%lim+1;
    if(u>v) swap(u,v);
    cout<<n<<' '<<u<<' '<<v<<'\n';
    for(int i=1;i<=n;i++) cout<<rand()%lim+1<<' ';
    cout<<'\n';
}
namespace OUT
{
    const int WZW=4000010,mo=998244353,g=3,gi=(mo+1)/3; 
    int A(int x,int y){return (0ll+x+y+mo)%mo;}
    int M(int x,int y){return 1ll*x*y%mo;}
    int ksm(int x,int y)
    {
	int s=1,t=x;
	while(y) {
	    if(y&1) s=M(s,t);
	    y>>=1,t=M(t,t);
	}
	return s;
    } 
    int ni(int x){return ksm(x,mo-2);}
    int JC[WZW],NI[WZW];
    int C(int n,int m){if(n<m) return 0;return M(JC[n],M(NI[m],NI[n-m]));} 
    int P(int n,int m){if(n<m) return 0;return M(JC[n],NI[n-m]);} 
    void prejc()
    {
	int n=4000000;
	JC[0]=1;
	for(int i=1;i<=n;i++) JC[i]=M(JC[i-1],i);
	NI[n]=ni(JC[n]);
	for(int i=n;i>=1;i--) NI[i-1]=M(NI[i],i);
    }
    const int N=4040400;
    int n,u,v,p,X[N],Y[N],b[N],a[N],lim,r[N],l;
    void INIT()
    {
	for(int i=0;i<N;i++) X[i]=Y[i]=a[i]=b[i]=r[i]=0;
	l=lim=n=u=v=p=0;
    }    
    void NTT(int *T,int type)
    {
	for(int i=0;i<lim;i++) if(i<r[i]) swap(T[i],T[r[i]]);
	for(int k=1;k<lim;k<<=1) {
	    int dis=k<<1;
	    int wn=ksm(type?g:gi,(mo-1)/dis);
	    for(int j=0;j<lim;j+=dis)
		for(int i=j,w=1;i<j+k;i++,w=M(w,wn)) {
		    int x=T[i],y=M(w,T[i+k]);
		    T[i]=A(x,y);
		    T[i+k]=A(x,-y);
		}
	}
    }
    
    int main()
    {
	prejc();
	n=read(),u=read(),v=read();
	p=A(1,-M(u,ni(v)));
	for(int i=1;i<=n;i++) a[i]=read(); 
	for(int i=0;i<=n;i++) {
	    X[i]=(i&1)?-NI[i]:NI[i];
	    Y[i]=M(a[i],NI[i]);
	}
	lim=1,l=0;
	while(lim<=(n*2)) lim<<=1,l++;
	for(int i=0;i<lim;i++) r[i]=(r[i>>1]>>1)|((1&i)<<(l-1));
	NTT(X,1);
	NTT(Y,1);
	for(int i=0;i<lim;i++) X[i]=M(X[i],Y[i]);
	NTT(X,0);
	int nim = ni(lim);
	for(int i=0;i<lim;i++) X[i]=M(X[i],nim);
	for(int i=1;i<=n;i++) b[i]=M(X[i],JC[i]);
	int ans=0;
	for(int snc=1,i=1;i<=n;i++) {
	    snc=M(snc,p);
	    ans=A(ans,M(M(b[i],C(n,i)),ni(1-snc)));
	}
	cout<<ans;
	return 0;
    }
}
char s1[1010],s2[1010];
void getid(int id)
{
    sprintf(s1,"cure%d.in",id);
    sprintf(s2,"cure%d.out",id);
}
int main()
{
    srand(time(0));
    for(int i=1;i<=5;i++) {
	getid(i);
	freopen(s1,"w",stdout);
	input();
	freopen(s1,"r",stdin);
	freopen(s2,"w",stdout);
	OUT::INIT();
	cerr<<i<<": ";
	OUT::main();
	cerr<<clock()<<'\n';
    }
}
/*
5 7 9
233 2333 23333 233333 2333333
3 1 1
1 1 1
*/
