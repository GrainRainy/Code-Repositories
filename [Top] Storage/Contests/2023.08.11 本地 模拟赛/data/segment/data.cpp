#include<bits/stdc++.h>
using namespace std;
int nn[]={0,10,456,500,998,1000,100000,100000,100000,500000,500000};
char s1[1010],s2[1010];
void getname(int id)
{
    sprintf(s1,"segment%d.in",id);
    sprintf(s2,"segment%d.out",id);
}
void input(int id)
{
    int n=nn[id],tp=0;
    if(id>=6&&id<=7) tp=1;
    cout<<n<<'\n';
    for(int i=1;i<=n;i++) cout<<rand()%100000+1<<' ';
    cout<<'\n';
    if(tp) for(int i=2;i<=n;i++) cout<<1<<' ';
    else for(int i=2;i<=n;i++) cout<<rand()%100000+1<<' ';
    cout<<'\n';
}
namespace OUT
{
#define int long long 
#define rint register int 
#define I inline 
#define lc (u<<1)
#define rc (u<<1|1)
    inline int read()
    {
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s;
    }
    const int N=1010010,INF=1e18;
    int f[N][21][2],n,a[N],b[N],lg[N],ans;
    void init()
    {
	memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
    }
    //f[i][j][0] i to its jth ancestor
    //f[i][j][1] i to its jth ancestor 's another son
    I int d(int x,int y){return (x>>y)^1;}
    void predp()
    {
	for(rint i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(rint u=n;u>=1;u--) {
	    if(lc>n) {
		for(rint sum=b[u],fa=u>>1,i=0;i<=lg[u];sum+=b[fa],i++,fa>>=1) {
		    f[u][i][0]=sum*a[fa];
		    int t=d(u,i);
		    f[u][i][1]=(sum+b[t])*a[t];
		}
	    }
	    else if(rc>n) {
		for(rint i=0;i<=lg[u];i++)
		    f[u][i][0]=a[lc]*b[lc]+f[lc][i+1][0],f[u][i][1]=a[lc]*b[lc]+f[lc][i+1][1];
	    }
	    else {
		for(rint i=0;i<=lg[u];i++) {
    f[u][i][0]=min(a[rc]*b[rc]+f[rc][0][1]+f[lc][i+1][0],a[lc]*b[lc]+f[lc][0][1]+f[rc][i+1][0]);
    f[u][i][1]=min(a[rc]*b[rc]+f[rc][0][1]+f[lc][i+1][1],a[lc]*b[lc]+f[lc][0][1]+f[rc][i+1][1]);
		}
	    }
	}
    }
    void MAIN()
    {
	n=read();
	for(rint i=1;i<=n;i++) a[i]=read();
	for(rint i=2;i<=n;i++) b[i]=read();
	predp();
	cout<<f[1][0][0]<<'\n'; 
    }
}
signed main()
{
    for(int i=1;i<=10;i++) {
	getname(i);
	freopen(s1,"w",stdout);
	input(i);
	freopen(s1,"r",stdin);
	freopen(s2,"w",stdout);
	OUT::init();
	OUT::MAIN();
	cerr<<i<<' '<<clock()<<'\n';
    }
}
