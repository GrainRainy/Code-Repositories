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
int a[N];
int main(){
	ll n,m,q;
	rd(n);rd(m);rd(q);
	ll s1,s2,e1,e2;
	ll g=__gcd(n,m);
	ll A=n/g,B=m/g;
	while(q--){
		rd(s1);rd(e1);rd(s2);rd(e2);
		ll x,y;
		if(s1==1) x=((e1+A-1)/A);
		else x=((e1+B-1)/B);
		if(s2==1) y=((e2+A-1)/A);
		else y=((e2+B-1)/B);
		puts(x==y?"YES":"NO");
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
