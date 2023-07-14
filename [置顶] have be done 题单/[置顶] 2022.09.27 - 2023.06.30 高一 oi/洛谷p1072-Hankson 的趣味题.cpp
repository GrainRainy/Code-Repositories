#include <iostream>
#include <cstring>
#include <algorithm>

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
	static short st[16], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int a, b, c, d;
int ans;

inline void solve(){
	ans = 0;
	input(a), input(b), input(c), input(d);
	for (int i = 1; i <= d / i; i ++){
		if (d % i == 0){
			int x = i, y = d / i;
			if (x % b == 0 and __gcd(x / b, a / b) == 1 and __gcd(d / c, d / x) == 1) ans ++;
			if (x == y) continue;
			if (y % b == 0 and __gcd(y / b, a / b) == 1 and __gcd(d / c, d / y) == 1) ans ++;
		}
	}
	return output(ans), void();
}

int main(){
	int t; input(t);
	while (t --) solve();
	return 0;
}
