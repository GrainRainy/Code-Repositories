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
const int N=105;
int a[N][N],b[N][N];
int c[N],d[N];
int n,m;
int main(){
	int T;
	rd(T);
	while(T--){
		rd(n);rd(m);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				rd(a[i][j]);
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				rd(b[i][j]);
			}
		}
		bool fl=true;
		for(int i=1;i<=n;++i){
			int cnt=0;
			int y=1,x=i;
			while(x>=1&&y<=m){
				c[++cnt]=a[x][y];
				d[cnt]=b[x][y];
				++y;--x;
			}
			sort(c+1,c+cnt+1);
			sort(d+1,d+cnt+1);
			for(int j=1;j<=cnt;++j){
				if(c[j]!=d[j]) fl=false;
			}
		}
		for(int j=1;j<=m;++j){
			int cnt=0;
			int x=n,y=j;
			while(x>=1&&y<=m){
				c[++cnt]=a[x][y];
				d[cnt]=b[x][y];
				++y;--x;
			}
			sort(c+1,c+cnt+1);
			sort(d+1,d+cnt+1);
			for(int i=1;i<=cnt;++i){
				if(c[i]!=d[i]) fl=false;
			}
		}
		puts(fl?"YES":"NO");
	}
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
