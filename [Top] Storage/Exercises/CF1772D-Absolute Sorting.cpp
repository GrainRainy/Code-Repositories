#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n'){
	if (x < 0) putchar('-'), x = -x;
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top -- ] | '0');
	putchar(ed);
}

const int N = 2e5 + 10;
int n;
int a[N];
int maxn, minn = 1;

inline void solve(){
	input(n);
	for (int i = 1; i <= n; ++ i) input(a[i]);
	// input
	maxn = 1e8, minn = 1;
	// init
	for (int i = 1; i <= n - 1; ++ i){
		if (a[i] == a[i + 1]) continue;
		double mid = (a[i] + a[i + 1]) / 2.0;
		if (a[i] > a[i + 1]) minn = max(minn, (int)ceil(mid));
		else maxn = min(maxn, (int)floor(mid));
	}
	if (maxn >= 0 and maxn >= minn) output(maxn);
	else output(-1);
}

int main(){
	int t; input(t);
	while (t --) solve();
	return 0;
}
