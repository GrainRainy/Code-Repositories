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
const int N=1e5+5;
const int M=7;
const int inf=0x3f3f3f3f;
int T;
int n,m=7;
bool f[1<<M];
int g[N];
int a[N][M];
int k1,k2;
bool che(int mid){
	memset(f,0,sizeof f);
	for(int i=1;i<=n;++i){
		int S=0;
		for(int j=0;j<m;++j){
			if(a[i][j]>=mid) S|=(1<<j);
		}
		g[i]=S;
		f[S]=1;
	}
	for(int S=(1<<m)-1;S>=0;--S){
		if(f[S]) continue;
		for(int j=0;j<m;++j){
			if(((S>>j)&1)==0){
				if(f[S^(1<<j)]){
					f[S]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		int tmp=(1<<m)-1-g[i];
		if(f[tmp]) {
			return true;
		}
	}
	return false;
}
int main(){
	rd(n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			rd(a[i][j-1]);
		}
	}
	int L=0,R=inf;
	int ans=0;
	while(L<=R){
		int mid=(L+R)/2;
		if(che(mid)) {
			ans=mid;L=mid+1;
		}else{
			R=mid-1;
		}
	}
	cout<<ans<<endl;
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
