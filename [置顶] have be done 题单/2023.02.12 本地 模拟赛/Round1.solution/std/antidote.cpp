#include<bits/stdc++.h>
#define reg register int
#define il inline
#define fi first
#define se second
#define mk(a,b) make_pair(a,b)
#define numb (ch^'0')
#define pb push_back
#define solid const auto &
#define enter cout<<endl
#define pii pair<int,int>
using namespace std;
typedef long long ll;
template<class T>il void rd(T &x){
    char ch;x=0;bool fl=false;while(!isdigit(ch=getchar()))(ch=='-')&&(fl=true);
    for(x=numb;isdigit(ch=getchar());x=x*10+numb);(fl==true)&&(x=-x);}
template<class T>il void output(T x){if(x/10)output(x/10);putchar(x%10+'0');}
template<class T>il void ot(T x){if(x<0) putchar('-'),x=-x;output(x);putchar(' ');}
template<class T>il void prt(T a[],int st,int nd){for(reg i=st;i<=nd;++i) ot(a[i]);putchar('\n');}
namespace Miracle{
const int N=200000+5;
int n,k;
int sz[N];
struct node{
	int nxt,to;
}e[2*N];
int hd[N],cnt;
int ans;
void add(int x,int y){
	e[++cnt].nxt=hd[x];
	e[cnt].to=y;
	hd[x]=cnt;
}
void dfs(int x,int fa){
	sz[x]=1;
	for(reg i=hd[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa) continue;
		dfs(y,x);
		sz[x]+=sz[y];
	}
	if(sz[x]>=k&&n-sz[x]>=k) ++ans;
}
int main(){
	rd(n);rd(k);
	int x,y;
	for(int i=1;i<n;++i){
		rd(x);rd(y);
		add(x,y);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}

}
signed main(){
    Miracle::main();
    return 0;
}

/*
   Author: *Miracle*
*/
