#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
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
using PII = pair<int, int>;
const int N = 3e5 + 10;
int n, a[N], f[N], siz[N], head[N], etp;
struct Node { int nxt, to; }edge[N << 1];

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void dp(int u, int fa) {
	siz[u] = 1, f[u] = a[u];
	vector<PII> sv;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == fa) continue;
		dp(v, u), siz[u] += siz[v];
		sv.push_back({f[v], siz[v] << 1});
	}
	sort(sv.begin(), sv.end(), [](const PII &a, const PII &b) {
		int resa = max(a.first, a.second + b.first);
		int resb = max(b.first, b.second + a.first);
		return resa < resb;
	});
	int res = 0;
	for (auto t : sv) {
		f[u] = max(f[u], res + t.first + 1);
		res += t.second;
	}
}

int main() {
	freopen("delivery.in", "r", stdin);
	freopen("delivery.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i], head[i] = -1;
	for (int i = 1, a, b; i < n; ++ i) cin >> a >> b, add(a, b), add(b, a);
	dp(1, 0);
	return cout << max(f[1], (n << 1) - 2 + a[1]) << '\n', 0;
}
