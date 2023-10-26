#include <iostream>
#define debug(x) cerr << #x << ' ' << x << '\n';
namespace IO{
	template<typename T> inline void rd(T &x){
		x=0;bool f=0;char c=0;
		while(c<'0'||c>'9') f|=c=='-',c=getchar();
		while('0'<=c&&c<='9') x=x*10+(c^48),c=getchar();
		x=f?-x:x;
	}
	template<typename T,typename ...Args> inline void rd(T &x,Args &...args){rd(x),rd(args...);}
	template<typename T> inline void wt(char c,T x){
		int stk[114],top=0;
		if(x<0) x=-x,putchar('-');
		do stk[++top]=x%10,x/=10; while(x);
		while(top) putchar(stk[top--]+'0');
		putchar(c);
	}
	template<typename T,typename ...Args> inline void wt(char c,T x,Args ...args){wt(c,x),wt(c,args...);}
	template<typename T,typename ...Args> inline void wt(char s,char c,T x,Args ...args){wt(c,x),wt(c,args...),putchar(s);}
};
using namespace IO;
using namespace std;
using LL = long long;
LL t, n, k, asa, asca, ascb, asb;

int count(int s) {
	int c = 0;
	for (; s; s >>= 1) c += s & 1;
	return c;
}

int comb(LL x) {
	LL res = 0;
	while (x) res += x % 10, x /= 10;
	return res;
}

void solve() {
	cin >> n >> k, asa = 10;
	for (int i = 0; i < 9; ++ i) {
		LL x = n + i * k, c = 0;
		while (x >= 10) x = comb(x), c ++;
		if (x < asa) asa = x, asca = c, ascb = i;
	}
	asb = asca + ascb;
	for (LL s = 0, c, tmpv; s < 1 << 11; s ++ ) {
		if (count(s) != asca) continue;
		tmpv = n, c = 0;
		for (int i = 0; i < 12 and tmpv > asa; ++ i)
			if ((s >> i) & 1) tmpv = comb(tmpv), c ++;
			else tmpv += k, c ++;
		asb = min(asb, c);
	}
	return cout << asa << ' ' << asb << '\n', void();
}

int main() {
	freopen("humility.in", "r", stdin);
	freopen("humility.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t; while (t --) solve();
	return 0;
}
