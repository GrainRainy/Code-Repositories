#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
const int W=10101000;
int mx=1e3,d=1e3,X[W],Y[W];
void input(int op)
{
    int n=8-rand()%1,k=rand()%n+1;
    cout<<n<<' '<<k<<'\n';
    for(int i=1;i<=n;i++) X[i]=rand()%mx+1,Y[i]=rand()%mx+1;
    if(op!=1) {
	sort(X+1,X+n+1,greater<int>());
	sort(Y+1,Y+n+1,less<int>());
	if(op==4) {
	    int t=rand()%n/10+1;
	    for(int i=n-t+1;i<=n;i++) X[i]=rand()%mx+1,Y[i]=rand()%mx+1;
	}
    }
    if(op==3||op==5) {
	int t=rand()%n/10+1;
	for(int i=n-t+1;i<=n;i++) X[i]=rand()%d+1,Y[i]=rand()%d+1;
    }
    for(int i=1;i<=n;i++) cout<<X[i]<<' '<<Y[i]<<'\n';
}
char s1[1010],s2[1010];
void getid(int id)
{
    sprintf(s1,"guard%d.in",id);
    sprintf(s2,"guard%d.out",id);
}
namespace OUT
{
    const int N=1010100,INF=1e15;
    struct poi{int x,y;}a[N],sta[N];
    bool operator <(poi x,poi y){return x.x==y.x?x.y<y.y:x.x<y.x;}
    int n,k,ans,sum,top,wfy[N],cnt;
    //wfy -> laji 
    priority_queue<int,vector<int>,greater<int> >q;
    void INIT()
    {
	for(int i=0;i<N;i++) a[i].x=a[i].y=sta[i].x=sta[i].y=wfy[i]=0;
	n=k=ans=sum=top=cnt=0;
	while(!q.empty()) q.pop();
    }
    signed main()
    {
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
	    while(top&&a[i].y>=sta[top].y) {wfy[++cnt]=(sta[top].x+sta[top].y);top--;}
	    sta[++top]=a[i];
	}
	sort(wfy+1,wfy+cnt+1);
	for(int i=1;i<=cnt;i++) wfy[i]+=wfy[i-1];
	sum=sta[1].y+sta[top].x;
	ans=cnt>=(k-1)?wfy[k-1]+sum:INF;
	int d=k-1;
	for(int i=2;i<=top;i++) q.push(sta[i-1].x+sta[i].y);
	while(!q.empty()) {
	    sum+=q.top();
	    q.pop();
	    d--;
	    if(d<=cnt) ans=min(ans,sum+wfy[d]);
	    if(d>=0&&d<=cnt) ans=min(ans,sum+wfy[d]);
	}
	cout<<ans*2<<'\n';
	cerr<<top<<' '<<ans<<' '<<sum<<'\n';
	return 0;
    }
}
signed main()
{
    srand(time(0));
    for(int i=1;i<=5;i++) {
	getid(i);
	freopen(s1,"w",stdout);
	input(i);
	freopen(s1,"r",stdin);
	freopen(s2,"w",stdout);
	OUT::INIT();
	cerr<<i<<": ";
	OUT::main();
    }
}
